#ifndef PACKAGETEMPLATEMANAGER_HPP
#define PACKAGETEMPLATEMANAGER_HPP

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "../../Model/PackageTemplateModel/packagetemplatemodel.hpp"

class PackageTemplateManager
{
public:
    PackageTemplateManager(const QJsonObject& json);
    QJsonObject DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
    void AddSample(const QJsonObject& json);
    void ChangeElement(const QJsonObject& json);
private:
    QVector<PackageTemplateModel> __models;
};

#endif // PACKAGETEMPLATEMANAGER_HPP
