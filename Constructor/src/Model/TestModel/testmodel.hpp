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

    void setName(const QString& name);
    void setStationId(const size_t& station_id);
    void setSequenceOfPackages(const QVector<SequenceOfPackageModel>& sequence_of_packages);
    void setDescription(const QString& description);

    size_t getId();
    QString getName();
    size_t getStationId();
    QVector<SequenceOfPackageModel> getSequenceOfPackagesById(const size_t& id);
    SequenceOfPackageModel getSequenceOfPackagesModelByPos(const size_t& pos);
    QString getDescription();

    void constructFromJson(const QJsonObject& json);
    QJsonObject dumpToJson();

private:
    size_t __id;
    static size_t __last_id;
    QString __name;
    size_t __station_id;
    SequenceOfPackageManager __sequence_of_packages;
    QString __description;
};

#endif // TESTMODEL_HPP
