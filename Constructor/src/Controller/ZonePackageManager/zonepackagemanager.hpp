#ifndef ZONEPACKAGEMANAGER_HPP
#define ZONEPACKAGEMANAGER_HPP

#include <QColor>
#include <QJsonObject>
#include<QJsonArray>
#include "../../Model/ZonePackageModel/zonepackagemodel.hpp"


class ZonePackageManager
{
public:
    //ZonePackageManager(const QJsonObject& json);
    static ZonePackageManager& getInstance(const QJsonObject& json);

    QVector<QString> getAllNames();
    ZonePackageModel& getModel(const size_t& id);
    ZonePackageModel& getModel(const QString& name);

    void changeElement(const size_t& id, const QString& name, const QColor& color);
    void changeElement(const QString& name, const QColor& color);
    void deleteElement(const size_t& id);
    void deleteElement (const QString& name);
    void addElement(const QString& name, const QColor& color);

    void constructFromJson(const QJsonObject& json);
    QJsonObject dumpToJson();

signals:
    void modelChanged(const size_t& pos);
    void modelDeleted(const size_t& size);
    void modelAdded(const size_t& size);
private:
    QVector<ZonePackageModel> __models;

    ZonePackageManager(const QJsonObject& json);
};

#endif // ZONEPACKAGEMANAGER_HPP
