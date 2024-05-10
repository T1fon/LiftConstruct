#ifndef PACKAGEMODEL_HPP
#define PACKAGEMODEL_HPP

#include <QObject>
#include <QJsonObject>
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
    void SetStationId(const size_t& station_id);
    void SetPackageTamplateId(const size_t& package_tamplate_id);
    void SetName(const QString& name);
    void SetData(const QVector<uint8_t>& data);
    void SetDescription(const QString &description);
    size_t GetId();
    size_t GetStationId();
    size_t GetPackageTemplateId();
    QString GetName();
    QVector<uint8_t> GetData();
    QString GetDescription();
    void SetByte(const size_t& index, const uint8_t& value);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();
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
