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


    void ConstructFromJson(const QJsonObject& json);
    QJsonArray DumpToJson();

    const TestModel& GetTestById(const size_t& id);
    const TestModel& GetTestByName(const QString& name);

private:
    QVector<TestModel> __models;

    TestManager(const QJsonObject& json);
    TestManager(const TestManager&) = delete;
    TestManager& operator=(const TestManager&) = delete;
};

#endif // TESTMANAGER_HPP
