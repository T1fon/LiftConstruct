#ifndef TESTMANAGER_HPP
#define TESTMANAGER_HPP
#include "../../Model/TestModel/testmodel.hpp"
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QDebug>

class TestManager
{
public:
    //TestManager(const QJsonObject& json);
    static TestManager& getInstance(const QJsonObject& json);


    void constructFromJson(const QJsonObject& json);
    QJsonArray dumpToJson();

    const TestModel& getTestById(const size_t& id);
    const TestModel& getTestByName(const QString& name);

private:
    QVector<TestModel> __models;

    TestManager(const QJsonObject& json);
    TestManager(const TestManager&) = delete;
    TestManager& operator=(const TestManager&) = delete;
};

#endif // TESTMANAGER_HPP
