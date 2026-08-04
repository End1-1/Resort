$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $PSScriptRoot
$RcFile = Join-Path $Root "Resort\rc.h"
$BuildDir = "D:\build.6.10.2\resort\release"
$ExePath = Join-Path $BuildDir "Resort.exe"
$Staging = Join-Path $PSScriptRoot "staging"
$QtBin = "C:\Development\Qt\6.10.2\msvc2022_64\bin"
$WinDeployQt = Join-Path $QtBin "windeployqt.exe"
$OpenSslBin = "C:\Development\OpenSSL-Win64\bin"
$Iscc = "C:\Program Files (x86)\Inno Setup 6\ISCC.exe"

if (-not (Test-Path $RcFile)) {
    throw "Version file not found: $RcFile"
}

$rcContent = Get-Content $RcFile -Raw
$m = [regex]::Match($rcContent, '#define\s+_PRODUCT_VERSION\s+(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)')
if (-not $m.Success) {
    throw "Cannot parse _PRODUCT_VERSION from $RcFile"
}

$VersionMajor = [int]$m.Groups[1].Value
$VersionMinor = [int]$m.Groups[2].Value
$VersionPatch = [int]$m.Groups[3].Value
$VersionBuild = [int]$m.Groups[4].Value

$VersionDot = "$VersionMajor.$VersionMinor.$VersionPatch.$VersionBuild"
$VersionUs = "${VersionMajor}_${VersionMinor}_${VersionPatch}_${VersionBuild}"
$OutputBaseFilename = "setup_resort_$VersionUs"

Write-Host "Version from rc.h: $VersionDot"

if (-not (Test-Path $BuildDir)) {
    throw "Build directory not found: $BuildDir"
}

Write-Host "Building Resort (Release)..."
$VsWhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
$VsInstall = & $VsWhere -latest -property installationPath
$VcVars = Join-Path $VsInstall "VC\Auxiliary\Build\vcvars64.bat"
if (-not (Test-Path $VcVars)) {
    throw "vcvars64.bat not found: $VcVars"
}
$buildCmd = "call `"$VcVars`" >nul && cmake --build `"$BuildDir`""
cmd /c $buildCmd
if ($LASTEXITCODE -ne 0) {
    throw "cmake build failed with exit code $LASTEXITCODE"
}

if (-not (Test-Path $ExePath)) {
    throw "Executable not found: $ExePath"
}

Write-Host "Preparing staging directory: $Staging"
if (Test-Path $Staging) {
    Remove-Item $Staging -Recurse -Force
}
New-Item -ItemType Directory -Path $Staging | Out-Null

Copy-Item $ExePath $Staging

Write-Host "Running windeployqt..."
& $WinDeployQt --release --compiler-runtime --force --dir $Staging $Staging\Resort.exe
if ($LASTEXITCODE -ne 0) {
    throw "windeployqt failed with exit code $LASTEXITCODE"
}

$SqlDriver = "C:\Development\Qt\6.10.2\msvc2022_64\plugins\sqldrivers\qsqlmysql.dll"
$SqlDest = Join-Path $Staging "sqldrivers"
if (-not (Test-Path $SqlDest)) {
    New-Item -ItemType Directory -Path $SqlDest | Out-Null
}
Copy-Item $SqlDriver $SqlDest -Force

# Qt QMYSQL plugin (qsqlmysql.dll) depends on MariaDB Connector C client library
$MariaClientCandidates = @(
    "C:\Development\mariadb\connectors\lib\libmariadb.dll",
    "C:\Program Files\MariaDB\MariaDB Connector C 64-bit\lib\libmariadb.dll",
    "C:\Program Files\MariaDB 10.11\lib\libmariadb.dll"
)
$MariaClient = $MariaClientCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1
if ($MariaClient) {
    Write-Host "Copying MariaDB client: $MariaClient"
    Copy-Item $MariaClient $Staging -Force
} else {
    throw "libmariadb.dll not found. QMYSQL driver will not load without it. Checked: $($MariaClientCandidates -join '; ')"
}

foreach ($dll in @("libssl-3-x64.dll", "libcrypto-3-x64.dll")) {
    $src = Join-Path $OpenSslBin $dll
    if (Test-Path $src) {
        Copy-Item $src $Staging -Force
    } else {
        Write-Warning "OpenSSL runtime not found: $src"
    }
}

# Qt6Core depends on icuuc.dll, which is a Windows forwarder to icu.dll.
# windeployqt copies only the forwarder; ship the real ICU from System32 for older/target PCs.
$IcuSourceDir = Join-Path $env:WINDIR "System32"
foreach ($dll in @("icu.dll", "icuuc.dll", "icuin.dll")) {
    $src = Join-Path $IcuSourceDir $dll
    if (Test-Path $src) {
        Write-Host "Copying ICU: $src"
        Copy-Item $src $Staging -Force
    } else {
        Write-Warning "ICU runtime not found: $src"
    }
}

$HelpFile = Join-Path $Root "help.html"
if (Test-Path $HelpFile) {
    Copy-Item $HelpFile $Staging -Force
}

$TouchQss = Join-Path $Root "Resort\SmartHotelTouch.qss"
if (Test-Path $TouchQss) {
    Write-Host "Copying SmartHotelTouch.qss"
    Copy-Item $TouchQss $Staging -Force
} else {
    Write-Warning "SmartHotelTouch.qss not found: $TouchQss"
}

$builtVersion = (Get-Item $ExePath).VersionInfo.FileVersion
Write-Host "Built executable version: $builtVersion"
if ($builtVersion -ne $VersionDot) {
    throw "Executable version mismatch. Expected $VersionDot, got $builtVersion"
}

if (-not (Test-Path $Iscc)) {
    throw "Inno Setup compiler not found: $Iscc"
}

Write-Host "Building installer: $OutputBaseFilename.exe"
Push-Location $PSScriptRoot
try {
    & $Iscc "/DMyAppVersion=$VersionDot" "/DMyOutputBaseFilename=$OutputBaseFilename" "resort.iss"
    if ($LASTEXITCODE -ne 0) {
        throw "ISCC failed with exit code $LASTEXITCODE"
    }
} finally {
    Pop-Location
}

$InstallerPath = Join-Path $PSScriptRoot "$OutputBaseFilename.exe"
if (-not (Test-Path $InstallerPath)) {
    throw "Installer was not created: $InstallerPath"
}

Write-Host "Done: $InstallerPath"
Get-Item $InstallerPath | Format-List FullName, Length, LastWriteTime
