#include "mainmanager.hpp"

MainManager::MainManager(const QJsonObject& json)
{
    if (json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "no pos name";
        return;
    }
    if (json.contains("last_redact_date"))
    {
        __last_redact_date = json["last_redact_date"].toString();
    }
    else
    {
        qDebug() << "no pos last_redact_date";
        return;
    }
    getStationManager(json);
    getTestManager(json);
    getZoneManager(json);
    getPackageManager(json);
}
StationManager& MainManager::getStationManager(const QJsonObject& json){return StationManager::getInstance(json);}
TestManager& MainManager::getTestManager(const QJsonObject& json){return TestManager::getInstance(json);}
ZonePackageManager& MainManager::getZoneManager(const QJsonObject& json){return ZonePackageManager::getInstance(json);}
PackageManager& MainManager::getPackageManager(const QJsonObject& json){return PackageManager::getInstance(json);}

MainManager& MainManager::getInstance(const QJsonObject& json)
{
    static MainManager instance(json);
    return instance;
}

QJsonObject MainManager::dumpToJson()
{
    QJsonObject json;
    json["name"] = __name;
    json["last_redact_date"] = __last_redact_date;
    json["package_zones"] = getZoneManager().dumpToJson();
    json["station"] = getStationManager().DumpToJson();
    json["packages"] = getPackageManager().DumpToJson();
    json["tests"] = getTestManager().DumpToJson();

    return json;
}


void MainManager::setName(const QString& name){__name = name;}
void MainManager::setDate(const QString& date){__last_redact_date = date;}
QString MainManager::getName(){return __name;}
QString MainManager::getDate(){return __last_redact_date;}

