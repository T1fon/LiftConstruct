#ifndef PACKAGEMANAGER_HPP
#define PACKAGEMANAGER_HPP
#include "../../Model/PackageModel/packagemodel.hpp"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>


class PackageManager
{
public:
    //PackageManager(const QJsonObject& json);

    static PackageManager& getInstance(const QJsonObject& json);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();
    const PackageModel& ReturnById(const size_t& id);
    const PackageModel& ReturnByName(const QString& name);
private:
    PackageManager(const QJsonObject& json);
    PackageManager(const PackageManager&) = delete;
    PackageManager& operator=(const PackageManager&) = delete;
    QVector<PackageModel> __models;
};

#endif // PACKAGEMANAGER_HPP
