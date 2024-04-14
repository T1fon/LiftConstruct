#ifndef ZONEPACKAGEMANAGER_H
#define ZONEPACKAGEMANAGER_H
#include <QJsonArray>
#include <QStringList>
#include "../ZonePackageModel/ZonePackageModel.h"

class ZonePackageManager
{
public:
    ZonePackageManager();
    ZonePackageManager(const QJsonArray &data);

    void fromQJsonArray(const QJsonArray &data);
    QJsonArray toJsonArray();

    void addZone(const QString& name, const QColor& color);

    //порождают исключения invalid_argument
    void modifyZone(const QString& name,const QColor& color);
    void modifyZone(const size_t& id,const QString& name,const QColor& color);
    void modifyZone(const ZonePackageModel& data);

    QStringList getAllZonesName();

    //порождают исключения invalid_argument
    ZonePackageModel getZone(const QString& name);
    ZonePackageModel getZone(const size_t& id);

    //порождают исключения invalid_argument
    void deleteZone(const QString& name);
    void deleteZone(const size_t& id);
signals:
    void modifyData(const ZonePackageModel&);
    void deleteData(ZonePackageModel);
private:

};

#endif // ZONEPACKAGEMANAGER_H
