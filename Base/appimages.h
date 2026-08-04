#ifndef APPIMAGES_H
#define APPIMAGES_H

#include <QByteArray>
#include <QString>

class DoubleDatabase;

namespace AppImages {

enum Purpose {
    PurposeReportLogo = 1,
    PurposeWelcomeLogo = 2
};

QString dir();
QString localPath(int purpose);
QString purposeFileName(int purpose);
int localVersion(int purpose);
void setLocalVersion(int purpose, int version);

/** Download newer blobs from DB into AppData when f_version is higher. */
bool syncFromDb(DoubleDatabase &db);

/**
 * Upsert image for purpose: stores PNG in DB, bumps f_version, updates local cache.
 * Returns new f_id or 0 on error (db.fLastError set).
 */
int saveToDb(DoubleDatabase &db, int purpose, const QByteArray &imageData, QString *error = nullptr);

/** Load blob for purpose from DB into memory (empty if missing). */
QByteArray loadFromDb(DoubleDatabase &db, int purpose);

/** Resolve known logo file names to AppData path, with fallback to relative path. */
QString resolveLogoPath(const QString &fileName);

}

#endif // APPIMAGES_H
