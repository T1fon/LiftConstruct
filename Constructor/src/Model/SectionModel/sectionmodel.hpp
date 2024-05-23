#ifndef SECTIONMODEL_HPP
#define SECTIONMODEL_HPP
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QString>
class SectionModel
{
public:
    SectionModel(const size_t& package_zone_id, const size_t& start_position, const size_t& size_section);
    SectionModel(const SectionModel& other);
    SectionModel(const QJsonObject& json);
    size_t& getPackageZoneId();
    size_t& getStartPosition();
    size_t& getSizeStation();
    void setPackageZoneId(const size_t& package_zone_id);
    void setStartPosition(const size_t& start_position);
    void setSizeStation(const size_t& size_section);
    QJsonObject toJson();
    void constructFromJson(const QJsonObject& json);
private:
    size_t __package_zone_id;
    size_t __start_position;
    size_t __size_section;
    void __ErrorMsg(QString target);
};

#endif // SECTIONMODEL_H
