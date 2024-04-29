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
    PackageManager(const QJsonObject& json);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpFromJson();
    const PackageModel& ReturnById(int id);
    const PackageModel& ReturnByName(QString name);
private:
    QVector<PackageModel> __models;
};

#endif // PACKAGEMANAGER_HPP
