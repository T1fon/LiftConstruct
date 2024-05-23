#ifndef SEQUENCEOFPACKAGEMANAGER_HPP
#define SEQUENCEOFPACKAGEMANAGER_HPP
#include "../../Model/SequenceOfPackageModel/sequenceofpackagemodel.hpp"

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>
#include <set>

class SequenceOfPackageManager
{
public:
    SequenceOfPackageManager(const QJsonObject& json);
    SequenceOfPackageManager(const QVector<SequenceOfPackageModel>& models);
    void constructFromJson(const QJsonObject& json);
    QJsonArray dumpToJson() ;
    SequenceOfPackageModel returnByPosition(const size_t& position);
    QVector<SequenceOfPackageModel> returnByPackageId(const size_t& package_id);
    void setPackages(const QVector<SequenceOfPackageModel>& sequence_of_packages);
private:
    std::set<SequenceOfPackageModel> __models;
};

#endif // SEQUENCEOFPACKAGEMANAGER_HPP
