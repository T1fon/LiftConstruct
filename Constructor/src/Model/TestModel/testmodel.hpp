#ifndef TESTMODEL_HPP
#define TESTMODEL_HPP
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include "../../Controller/SequenceOfPackageManager/sequenceofpackagemanager.hpp"

class TestModel
{
public:
    TestModel(const QJsonObject& json);
    TestModel(const QString& name, const size_t& station_id,
              const QVector<SequenceOfPackageModel>& sequence_of_packages, const QString& description);

    void SetName(const QString& name);
    void SetStationId(const size_t& station_id);
    void SetSequenceOfPackages(const QVector<SequenceOfPackageModel>& sequence_of_packages);
    void SetDescription(const QString& description);

    size_t GetId();
    QString GetName();
    size_t GetStationId();
    QVector<SequenceOfPackageModel> GetSequenceOfPackagesById(const size_t& id);
    SequenceOfPackageModel GetSequenceOfPackagesModelByPos(const size_t& pos);
    QString GetDescription();

    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();

private:
    size_t __id;
    static size_t __last_id;
    QString __name;
    size_t __station_id;
    SequenceOfPackageManager __sequence_of_packages;
    QString __description;
};

#endif // TESTMODEL_HPP
