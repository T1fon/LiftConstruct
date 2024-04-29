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
    PackageModel(int station_id, int p_t_id, QString name, QVector<uint8_t> data, QString description);
    void SetStationId(int station_id);
    void SetPackageTamplateId(int package_tamplate_id);
    void SetName(QString name);
    void SetData(QVector<uint8_t> data);
    void SetDescription(QString description);
    int GetId();
    int GetStationId();
    int GetPackageTemplateId();
    QString GetName();
    QVector<uint8_t> GetData();
    QString GetDescription();
    void SetByte(int index, uint8_t value);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();
private:
    static int __last_id;
    int __id;
    int __station_id;
    int __package_template_id;
    QString __name;
    QVector<uint8_t> __data;
    QString __description = "";
};

#endif // PACKAGEMODEL_HPP
