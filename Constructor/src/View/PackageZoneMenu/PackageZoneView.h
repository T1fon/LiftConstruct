#ifndef PACKAGEZONEVIEW_H
#define PACKAGEZONEVIEW_H
#include <QObject>
#include <qqml.h>

#include "../../Controller/MainManager/mainmanager.hpp"

class PackageZoneView: public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    PackageZoneView(QObject *parent = nullptr);
signals:
    void addPackageZoneSig(const QString& name, const QColor& color);
    void clearPackageZone();
public slots:
    void loadPackageZones();
    void addPackageZone(const QString& name, const QColor& color);
    void changePackageZone(const QString& name, const QColor& color);
    void deletePackageZone(const QString& name);
};

#endif // PACKAGEZONEVIEW_H
