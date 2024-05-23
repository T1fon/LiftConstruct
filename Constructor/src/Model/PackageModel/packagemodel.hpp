#ifndef PACKAGEMODEL_HPP
#define PACKAGEMODEL_HPP

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <vector>

class PackageModel
{
public:
    PackageModel(const QJsonObject& json);
    PackageModel(const size_t& station_id, const size_t& p_t_id, const QString& name,
                 const QVector<uint8_t>& data, const QString& description);
    void setStationId(const size_t& station_id);
    void setPackageTamplateId(const size_t& package_tamplate_id);
    void setName(const QString& name);
    void setData(const QVector<uint8_t>& data);
    void setDescription(const QString &description);
    size_t getId();
    size_t getStationId();
    size_t getPackageTemplateId();
    QString getName();
    QVector<uint8_t> getData();
    QString getDescription();
    void setByte(const size_t& index, const uint8_t& value);
    void constructFromJson(const QJsonObject& json);
    QJsonObject dumpToJson();
private:
    static int __last_id;
    size_t __id;
    size_t __station_id;
    size_t __package_template_id;
    QString __name;
    QVector<uint8_t> __data;
    QString __description = "";
};

#endif // PACKAGEMODEL_HPP
