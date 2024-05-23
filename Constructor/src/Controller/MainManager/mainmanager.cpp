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
    json["packages"] = getPackageManager().dumpToJson();
    json["tests"] = getTestManager().dumpToJson();

    return json;
}

void MainManager::constructFromJson(QJsonObject json)
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

void MainManager::setName(const QString& name){__name = name;}
void MainManager::setDate(const QString& date){__last_redact_date = date;}
void MainManager::setPath(const QString& path){__path_json = path;}
QString MainManager::getName(){return __name;}
QString MainManager::getDate(){return __last_redact_date;}
QString MainManager::getPath(){return __path_json;}

QJsonObject MainManager::getJson(QString path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw std::runtime_error("Не удалось открыть файл для чтения");
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();
    return json;
}

void MainManager::saveJson()
{
    QFile file(__path_json);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        throw std::runtime_error("Не удалось открыть файл для записи");
    }

    QJsonDocument doc(dumpToJson());
    QByteArray data = doc.toJson();

    if (file.write(data) == -1) {
        throw std::runtime_error("Ошибка записи в файл");
    }

    file.close();
}


