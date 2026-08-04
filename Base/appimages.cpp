#include "appimages.h"
#include "doubledatabase.h"

#include <QBuffer>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QImage>
#include <QList>
#include <QSettings>
#include <QStandardPaths>

namespace AppImages {

static QSettings versionSettings()
{
    return QSettings(QDir(dir()).filePath(QStringLiteral("versions.ini")), QSettings::IniFormat);
}

QString dir()
{
    const QString path = QDir(QStandardPaths::writableLocation(QStandardPaths::GenericConfigLocation))
                             .filePath(QStringLiteral("SmartHotel/images"));
    QDir().mkpath(path);
    return path;
}

QString purposeFileName(int purpose)
{
    switch (purpose) {
    case PurposeReportLogo:
        return QStringLiteral("logo_print.png");
    case PurposeWelcomeLogo:
        return QStringLiteral("logo_welcome.png");
    default:
        return QStringLiteral("image_%1.png").arg(purpose);
    }
}

QString localPath(int purpose)
{
    return QDir(dir()).filePath(purposeFileName(purpose));
}

int localVersion(int purpose)
{
    return versionSettings().value(QString::number(purpose), 0).toInt();
}

void setLocalVersion(int purpose, int version)
{
    QSettings s = versionSettings();
    s.setValue(QString::number(purpose), version);
    s.sync();
}

static bool writeLocalFile(int purpose, const QByteArray &data, int version)
{
    QImage img;
    QByteArray png = data;
    if (img.loadFromData(data)) {
        QByteArray buf;
        QBuffer buffer(&buf);
        buffer.open(QIODevice::WriteOnly);
        if (img.save(&buffer, "PNG")) {
            png = buf;
        }
    }
    QFile f(localPath(purpose));
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return false;
    }
    if (f.write(png) != png.size()) {
        return false;
    }
    f.close();
    setLocalVersion(purpose, version);
    return true;
}

bool syncFromDb(DoubleDatabase &db)
{
    if (!db.exec(QStringLiteral("select f_id, f_purpose, f_version from f_images"))) {
        return false;
    }

    // Snapshot first: nested exec() replaces fDbRows and would crash on the next iteration.
    struct Item {
        int id = 0;
        int purpose = 0;
        int version = 0;
    };
    QList<Item> items;
    items.reserve(db.rowCount());
    for (int i = 0; i < db.rowCount(); ++i) {
        Item it;
        it.id = db.getValue(i, 0).toInt();
        it.purpose = db.getValue(i, 1).toInt();
        it.version = db.getValue(i, 2).toInt();
        if (it.purpose > 0) {
            items.append(it);
        }
    }

    for (const Item &it : items) {
        const QString path = localPath(it.purpose);
        if (QFile::exists(path) && localVersion(it.purpose) >= it.version) {
            continue;
        }
        db[":f_id"] = it.id;
        if (!db.exec(QStringLiteral("select f_image from f_images where f_id=:f_id")) || !db.nextRow()) {
            continue;
        }
        const QByteArray blob = db.getValue(0).toByteArray();
        if (blob.isEmpty()) {
            continue;
        }
        writeLocalFile(it.purpose, blob, it.version);
    }
    return true;
}

QByteArray loadFromDb(DoubleDatabase &db, int purpose)
{
    db[":f_purpose"] = purpose;
    if (!db.exec(QStringLiteral("select f_image from f_images where f_purpose=:f_purpose")) || !db.nextRow()) {
        return {};
    }
    return db.getValue(0).toByteArray();
}

int saveToDb(DoubleDatabase &db, int purpose, const QByteArray &imageData, QString *error)
{
    QImage img;
    if (!img.loadFromData(imageData)) {
        if (error) {
            *error = QObject::tr("Invalid image file");
        }
        return 0;
    }
    QByteArray png;
    QBuffer buffer(&png);
    buffer.open(QIODevice::WriteOnly);
    if (!img.save(&buffer, "PNG")) {
        if (error) {
            *error = QObject::tr("Cannot convert image to PNG");
        }
        return 0;
    }

    db[":f_purpose"] = purpose;
    int id = 0;
    int version = 1;
    if (db.exec(QStringLiteral("select f_id, f_version from f_images where f_purpose=:f_purpose")) && db.nextRow()) {
        id = db.getInt(0);
        version = db.getInt(1) + 1;
        db[":f_id"] = id;
        db[":f_image"] = png;
        db[":f_version"] = version;
        db[":f_purpose"] = purpose;
        if (!db.exec(QStringLiteral(
                "update f_images set f_image=:f_image, f_version=:f_version, f_purpose=:f_purpose where f_id=:f_id"))) {
            if (error) {
                *error = db.fLastError;
            }
            return 0;
        }
    } else {
        db[":f_image"] = png;
        db[":f_version"] = version;
        db[":f_purpose"] = purpose;
        id = db.insert(QStringLiteral("f_images"), true);
        if (id == 0) {
            if (error) {
                *error = db.fLastError;
            }
            return 0;
        }
    }

    if (!writeLocalFile(purpose, png, version)) {
        if (error) {
            *error = QObject::tr("Saved to database but failed to write local cache");
        }
    }
    return id;
}

QString resolveLogoPath(const QString &fileName)
{
    const QString name = QFileInfo(fileName).fileName();
    int purpose = 0;
    if (name.compare(QStringLiteral("logo_print.png"), Qt::CaseInsensitive) == 0) {
        purpose = PurposeReportLogo;
    } else if (name.compare(QStringLiteral("logo_welcome.png"), Qt::CaseInsensitive) == 0
               || name.compare(QStringLiteral("logo.png"), Qt::CaseInsensitive) == 0) {
        purpose = PurposeWelcomeLogo;
    }
    if (purpose > 0) {
        const QString cached = localPath(purpose);
        if (QFile::exists(cached)) {
            return cached;
        }
    }
    if (QFile::exists(fileName)) {
        return fileName;
    }
    return fileName;
}

} // namespace AppImages
