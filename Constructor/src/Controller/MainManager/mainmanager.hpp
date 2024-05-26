#ifndef MAINMANAGER_HPP
#define MAINMANAGER_HPP

#include <QObject>
#include "../PackageManager/packagemanager.hpp"
#include "../ZonePackageManager/zonepackagemanager.hpp"
#include "../TestManager/testmanager.hpp"
#include "../StationManager/stationmanager.hpp"
#include <QFile>

class MainManager
{

public:
    static MainManager& getInstance(const QJsonObject& json = QJsonObject());

    static QJsonObject dumpToJson();


    static void setName(const QString& name);
    static void setDate(const QString& date);
    static void setPath(const QString& path);
    static QString getName();
    static QString getDate();
    static QString getPath();
    static void constructFromJson(QJsonObject json);
    static QJsonObject getJson(QString path);
    static void saveJson();

    static StationManager& getStationManager(const QJsonObject& json = QJsonObject());
    static TestManager& getTestManager(const QJsonObject& json = QJsonObject());
    static ZonePackageManager& getZoneManager(const QJsonObject& json = QJsonObject());
    static PackageManager& getPackageManager(const QJsonObject& json = QJsonObject());

private:
    MainManager(const QJsonObject& json);
    MainManager(const MainManager&) = delete;
    MainManager& operator=(const MainManager&) = delete;

    static QString __name;
    static QString __last_redact_date;
    static QString __path_json;

};

#endif // MAINMANAGER_HPP
