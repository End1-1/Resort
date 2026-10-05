$ErrorActionPreference = "Stop"

$Root = Split-Path -Parent $PSScriptRoot
$Staging = Join-Path $PSScriptRoot "staging"
$QtBin = "C:\Development\Qt\6.10.2\msvc2022_64\bin"
$WinDeployQt = Join-Path $QtBin "windeployqt.exe"
$OpenSslBin = "C:\Development\OpenSSL-Win64\bin"
$Iscc = "C:\Program Files (x86)\Inno Setup 6\ISCC.exe"
$SqlDriver = "C:\Development\Qt\6.10.2\msvc2022_64\plugins\sqldrivers\qsqlmysql.dll"

function Get-QtCreatorReleaseBuildDir {
    param(
        [Parameter(Mandatory = $true)][string]$ProjectDir,
        [Parameter(Mandatory = $true)][string]$ExeName
    )

    $userFile = Join-Path $ProjectDir ".qtcreator\CMakeLists.txt.user"
    if (-not (Test-Path $userFile)) {
        return $null
    }

    [xml]$xml = Get-Content $userFile -Raw
    $ns = @{ ns = "http://www.qtproject.org/qtcreator" }
    # Qt Creator stores keys without a default xmlns in practice; match both.
    $nodes = Select-Xml -Xml $xml -XPath "//value[@key='ProjectExplorer.BuildConfiguration.BuildDirectory']"
    if (-not $nodes) {
        $nodes = Select-Xml -Xml $xml -XPath "//*[local-name()='value' and @key='ProjectExplorer.BuildConfiguration.BuildDirectory']"
    }

    $candidates = @()
    foreach ($n in $nodes) {
        $dir = [string]$n.Node.'#text'
        if ([string]::IsNullOrWhiteSpace($dir)) { continue }
        $exe = Join-Path $dir $ExeName
        if (Test-Path $exe) {
            $item = Get-Item $exe
            $candidates += [pscustomobject]@{
                Dir     = $dir
                Exe     = $item.FullName
                Written = $item.LastWriteTimeUtc
                Version = $item.VersionInfo.FileVersion
            }
        }
    }

    if ($candidates.Count -eq 0) {
        return $null
    }

    # Prefer a path that looks like Release; otherwise take the newest exe.
    $release = $candidates |
        Where-Object { $_.Dir -match '(?i)[\\/]release$' } |
        Sort-Object Written -Descending |
        Select-Object -First 1
    if ($release) {
        return $release
    }

    return $candidates | Sort-Object Written -Descending | Select-Object -First 1
}

function Resolve-ReleaseExe {
    param(
        [Parameter(Mandatory = $true)][string]$ProjectDir,
        [Parameter(Mandatory = $true)][string]$ExeName,
        [Parameter(Mandatory = $true)][string]$FallbackDir
    )

    $found = Get-QtCreatorReleaseBuildDir -ProjectDir $ProjectDir -ExeName $ExeName
    if ($found) {
        return $found
    }

    $fallbackExe = Join-Path $FallbackDir $ExeName
    if (Test-Path $fallbackExe) {
        $item = Get-Item $fallbackExe
        return [pscustomobject]@{
            Dir     = $FallbackDir
            Exe     = $item.FullName
            Written = $item.LastWriteTimeUtc
            Version = $item.VersionInfo.FileVersion
        }
    }

    throw "$ExeName not found. Build Release first. Checked Qt Creator build dirs in $ProjectDir and fallback $FallbackDir"
}

$Resort = Resolve-ReleaseExe `
    -ProjectDir (Join-Path $Root "Resort") `
    -ExeName "Resort.exe" `
    -FallbackDir "D:\build.6.10.2\resort\release"

$Updater = Resolve-ReleaseExe `
    -ProjectDir (Join-Path $Root "Updater") `
    -ExeName "Updater.exe" `
    -FallbackDir "D:\build.6.10.2\updater\release"

$ExePath = $Resort.Exe
$UpdaterExe = $Updater.Exe

$VersionDot = $Resort.Version
if ([string]::IsNullOrWhiteSpace($VersionDot)) {
    throw "Cannot read FileVersion from $ExePath"
}
$VersionUs = $VersionDot.Replace(".", "_")
$OutputBaseFilename = "setup_resort_$VersionUs"

Write-Host "Packaging installer from latest release builds:"
Write-Host ("  Resort:  {0}  (v{1}, {2:yyyy-MM-dd HH:mm})" -f $ExePath, $VersionDot, $Resort.Written.ToLocalTime())
Write-Host ("  Updater: {0}  (v{1}, {2:yyyy-MM-dd HH:mm})" -f $UpdaterExe, $Updater.Version, $Updater.Written.ToLocalTime())

Write-Host "Preparing staging directory: $Staging"
if (Test-Path $Staging) {
    Remove-Item $Staging -Recurse -Force
}
New-Item -ItemType Directory -Path $Staging | Out-Null

Copy-Item $ExePath $Staging
Write-Host "Copying Updater: $UpdaterExe"
Copy-Item $UpdaterExe (Join-Path $Staging "Updater.exe") -Force

Write-Host "Running windeployqt..."
& $WinDeployQt --release --compiler-runtime --force --dir $Staging $Staging\Resort.exe
if ($LASTEXITCODE -ne 0) {
    throw "windeployqt failed with exit code $LASTEXITCODE"
}

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
