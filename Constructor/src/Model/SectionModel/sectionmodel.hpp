#ifndef SECTIONMODEL_HPP
#define SECTIONMODEL_HPP
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
class SectionModel
{
public:
    SectionModel(int package_zone_id, int start_position, int size_section);
    SectionModel(const SectionModel& other);
    SectionModel(const QJsonObject& json);
    int GetPackageZoneId();
    int GetStartPosition();
    int GetSizeStation();
    void SetPackageZoneId(int package_zone_id);
    void SetStartPosition(int start_position);
    void SetSizeStation(int size_section);
    QJsonObject toJson();
    void ConstructFromJson(const QJsonObject& json);
private:
    int __package_zone_id;
    int __start_position;
    int __size_section;
    void __ErrorMsg(QString target);
};

#endif // SECTIONMODEL_H
