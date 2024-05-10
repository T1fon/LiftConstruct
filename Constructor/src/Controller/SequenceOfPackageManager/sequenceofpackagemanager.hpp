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
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson() ;
    const SequenceOfPackageModel& ReturnByPosition(const size_t& position);
    QVector<SequenceOfPackageModel> ReturnByPackageId(const size_t& package_id);
private:
    std::set<SequenceOfPackageModel> __models;
};

#endif // SEQUENCEOFPACKAGEMANAGER_HPP
