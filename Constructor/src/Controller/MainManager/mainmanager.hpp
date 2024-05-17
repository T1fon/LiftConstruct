#ifndef MAINMANAGER_HPP
#define MAINMANAGER_HPP
#include "../PackageManager/packagemanager.hpp"
#include "../ZonePackageManager/zonepackagemanager.hpp"
#include "../TestManager/testmanager.hpp"
#include "../StationManager/stationmanager.hpp"


class MainManager
{
public:

    static MainManager& getInstance(const QJsonObject& json = QJsonObject());

    QJsonObject dumpToJson();


    void setName(const QString& name);
    void setDate(const QString& date);
    QString getName();
    QString getDate();

private:

    MainManager(const QJsonObject& json);
    MainManager(const MainManager&) = delete;
    MainManager& operator=(const MainManager&) = delete;

    static StationManager& getStationManager(const QJsonObject& json = QJsonObject());
    static TestManager& getTestManager(const QJsonObject& json = QJsonObject());
    static ZonePackageManager& getZoneManager(const QJsonObject& json = QJsonObject());
    static PackageManager& getPackageManager(const QJsonObject& json = QJsonObject());

    QString __name;
    QString __last_redact_date;

};

#endif // MAINMANAGER_HPP
