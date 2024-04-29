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
    TestModel(QString name, int station_id, QVector<SequenceOfPackageManager> sequence_of_packages, QString description);
    void SetName(QString name);
    void SetStationId(int station_id);
    void SetSequenceOfPackages(QVector<SequenceOfPackageManager> sequence_of_packages);
    void SetDescription(QString description);
    int GetId();
    QString GetName();
    int GetStationId();
    QVector<SequenceOfPackageManager> GetSequenceOfPackages();
    QString GetDescription();
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();

private:
    int __id;
    static size_t __last_id;
    QString __name;
    int __station_id;
    QVector<SequenceOfPackageManager> __sequence_of_packages;
    QString __description;
};

#endif // TESTMODEL_HPP
