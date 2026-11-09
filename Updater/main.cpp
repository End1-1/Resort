#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QLabel>
#include <QMessageBox>
#include <QProcess>
#include <QProcessEnvironment>
#include <QProgressBar>
#include <QStandardPaths>
#include <QTimer>
#include <QUrl>
#include <QVBoxLayout>
#include <QWidget>

#ifdef Q_OS_WIN
#  include <windows.h>
#endif

#include "updatemanger.h"

namespace {

QString normalizeSetupVersion(QString version)
{
    version = version.trimmed();
    version.replace(QLatin1Char(','), QLatin1Char('_'));
    version.replace(QLatin1Char('.'), QLatin1Char('_'));
    version.remove(QLatin1Char(' '));
    return version;
}

QString setupDownloadUrl(const QString &version)
{
    return QStringLiteral("https://www.picasso.am/files/resort/setup_resort_%1.exe")
        .arg(normalizeSetupVersion(version));
}

QString setupFileName(const QString &version)
{
    return QStringLiteral("setup_resort_%1.exe").arg(normalizeSetupVersion(version));
}

QString setupFileNameFromUrl(const QString &url)
{
    const QString path = QUrl(url).path();
    const QString name = QFileInfo(path).fileName();
    if(!name.isEmpty()) {
        return name;
    }
    return QStringLiteral("setup_resort.exe");
}

void prepareQtFromAppDir(const QString &appDir)
{
    if(appDir.isEmpty()) {
        return;
    }
#ifdef Q_OS_WIN
    SetDllDirectoryW(reinterpret_cast<LPCWSTR>(appDir.utf16()));
#endif
    qputenv("PATH", QFile::encodeName(appDir) + ';' + qgetenv("PATH"));
    qputenv("QT_PLUGIN_PATH", QFile::encodeName(appDir));
    qputenv("QT_QPA_PLATFORM_PLUGIN_PATH",
            QFile::encodeName(QDir(appDir).filePath(QStringLiteral("platforms"))));
}

bool copyFileForce(const QString &src, const QString &dst)
{
    if(!QFile::exists(src)) {
        return false;
    }
    QDir().mkpath(QFileInfo(dst).absolutePath());
    if(QFile::exists(dst) && !QFile::remove(dst)) {
        return false;
    }
    return QFile::copy(src, dst);
}

// The host exe is started from %TEMP%. The Windows loader resolves Qt6*.dll
// before main(), and it does not look in the original install directory.
bool copyQtRuntime(const QString &appDir, const QString &hostDir)
{
    const QDir src(appDir);
    const QDir dst(hostDir);
    const QStringList names = src.entryList(
        {QStringLiteral("Qt6*.dll"),
         QStringLiteral("d3dcompiler_47.dll"),
         QStringLiteral("dxcompiler.dll"),
         QStringLiteral("dxil.dll"),
         QStringLiteral("opengl32sw.dll"),
         QStringLiteral("vcruntime*.dll"),
         QStringLiteral("msvcp140*.dll"),
         QStringLiteral("concrt140.dll")},
        QDir::Files);
    for(const QString &name : names) {
        if(!copyFileForce(src.filePath(name), dst.filePath(name))) {
            return false;
        }
    }
    if(!QFile::exists(dst.filePath(QStringLiteral("Qt6Widgets.dll")))) {
        return false;
    }

    const QStringList pluginDirs = {
        QStringLiteral("platforms"),
        QStringLiteral("styles")
    };
    for(const QString &sub : pluginDirs) {
        const QDir from(src.filePath(sub));
        if(!from.exists()) {
            continue;
        }
        const QStringList files = from.entryList(QDir::Files);
        for(const QString &name : files) {
            if(!copyFileForce(from.filePath(name), QDir(dst.filePath(sub)).filePath(name))) {
                return false;
            }
        }
    }
    return QFile::exists(QDir(dst.filePath(QStringLiteral("platforms")))
                         .filePath(QStringLiteral("qwindows.dll")));
}

void killResort()
{
#ifdef Q_OS_WIN
    QProcess::execute(QStringLiteral("taskkill.exe"),
                      {QStringLiteral("/F"),
                       QStringLiteral("/T"),
                       QStringLiteral("/IM"),
                       QStringLiteral("Resort.exe")});
#endif
}

/**
 * Self-update strategy:
 * 1. App starts {app}\Updater.exe
 * 2. Updater copies itself and the Qt DLLs to %TEMP%\SmartHotelUpdate\ and relaunches from there
 * 3. Host downloads setup via WinHTTP and runs Inno /SILENT
 * 4. Setup installs the new Updater.exe into {app}
 */
bool ensureRunningFromTemp(int argc, char *argv[])
{
    const QString self = QFileInfo(QString::fromLocal8Bit(argv[0])).absoluteFilePath();
    const QString appDir = QFileInfo(self).absolutePath();
    const QString tempDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    const QString hostDir = QDir(tempDir).filePath(QStringLiteral("SmartHotelUpdate"));
    const QString tempExe = QDir(hostDir).filePath(QStringLiteral("SmartHotelUpdateHost.exe"));

    const QString selfNative = QDir::toNativeSeparators(self);
    const QString tempNative = QDir::toNativeSeparators(tempExe);
    if(selfNative.compare(tempNative, Qt::CaseInsensitive) == 0) {
        const QByteArray envDir = qgetenv("SMARTHOTEL_APP_DIR");
        prepareQtFromAppDir(envDir.isEmpty() ? appDir : QString::fromLocal8Bit(envDir));
        return true;
    }

    QDir().mkpath(hostDir);
    QFile::remove(QDir(tempDir).filePath(QStringLiteral("PicassoUpdateHost.exe")));
    QFile::remove(QDir(tempDir).filePath(QStringLiteral("SmartHotelUpdateHost.exe")));
    if(!copyFileForce(self, tempExe) || !copyQtRuntime(appDir, hostDir)) {
        prepareQtFromAppDir(appDir);
        return true;
    }

    QStringList args;
    for(int i = 1; i < argc; ++i) {
        args << QString::fromLocal8Bit(argv[i]);
    }

    QProcess proc;
    proc.setProgram(tempExe);
    proc.setArguments(args);
    proc.setWorkingDirectory(appDir);

    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    const QString path = env.value(QStringLiteral("PATH"));
    env.insert(QStringLiteral("PATH"), appDir + QLatin1Char(';') + path);
    env.insert(QStringLiteral("QT_PLUGIN_PATH"), appDir);
    env.insert(QStringLiteral("QT_QPA_PLATFORM_PLUGIN_PATH"),
               QDir(appDir).filePath(QStringLiteral("platforms")));
    env.insert(QStringLiteral("SMARTHOTEL_APP_DIR"), appDir);
    proc.setProcessEnvironment(env);

    if(!proc.startDetached()) {
        prepareQtFromAppDir(appDir);
        return true;
    }
    return false;
}

} // namespace

int main(int argc, char *argv[])
{
    if(!ensureRunningFromTemp(argc, argv)) {
        return 0;
    }

    QApplication a(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(QStringLiteral("SmartHotel Updater"));
    parser.addHelpOption();
    QCommandLineOption appOpt(QStringLiteral("app"), QStringLiteral("Application module name"), QStringLiteral("module"));
    QCommandLineOption verOpt(QStringLiteral("version"), QStringLiteral("Version to update to"), QStringLiteral("version"));
    QCommandLineOption urlOpt(QStringLiteral("url"), QStringLiteral("Full setup download URL"), QStringLiteral("url"));
    parser.addOption(appOpt);
    parser.addOption(verOpt);
    parser.addOption(urlOpt);
    parser.process(a);

    const QString module = parser.value(appOpt).trimmed().toLower();
    const QString version = parser.value(verOpt).trimmed();
    QString url = parser.value(urlOpt).trimmed();
    if(url.isEmpty() && !version.isEmpty()) {
        url = setupDownloadUrl(version);
    }
    if(url.isEmpty()
            || (!module.isEmpty()
                && module != QLatin1String("resort")
                && module != QLatin1String("smarthotel"))) {
        QMessageBox::critical(nullptr, QStringLiteral("Updater"),
                              QStringLiteral("Missing or invalid arguments.\n"
                                             "Usage: Updater --app=resort --version=<X.Y.Z.W> [--url=<setup-url>]"));
        return 1;
    }

    const QString fileName = version.isEmpty()
            ? setupFileNameFromUrl(url)
            : setupFileName(version);

    QWidget w;
    w.setWindowTitle(QStringLiteral("SmartHotel Update"));
    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);
    auto *layout = new QVBoxLayout(&w);
    auto *label = new QLabel(QStringLiteral("Preparing update…"), &w);
    label->setWordWrap(true);
    label->setMinimumHeight(72);
    auto *pb = new QProgressBar(&w);
    pb->setRange(0, 100);
    pb->setTextVisible(true);
    layout->addWidget(label);
    layout->addWidget(pb);
    w.resize(480, 150);
    w.show();
    w.raise();
    w.activateWindow();

    label->setText(QStringLiteral("Closing SmartHotel…"));
    killResort();

    UpdateManager um(url, fileName);
    um.setProgressBar(pb);
    um.setHostWindow(&w);
    QObject::connect(&um, &UpdateManager::statusChanged, label, &QLabel::setText);
    QObject::connect(&um, &UpdateManager::aboutToElevate, &w, [&w]() {
        w.setWindowFlag(Qt::WindowStaysOnTopHint, false);
        w.showNormal();
        w.lower();
    });
    QObject::connect(&um, &UpdateManager::error, [&](const QString &msg) {
        w.setWindowFlag(Qt::WindowStaysOnTopHint, false);
        w.show();
        QMessageBox::critical(&w, QStringLiteral("Update error"), msg);
        a.quit();
    });
    QObject::connect(&um, &UpdateManager::finished, [&]() {
        QTimer::singleShot(2500, &a, &QApplication::quit);
    });
    um.start();
    return a.exec();
}
