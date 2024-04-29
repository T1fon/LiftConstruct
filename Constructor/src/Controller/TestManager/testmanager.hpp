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
    TestManager(const QJsonObject& json);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpFromJson();
    const TestModel& GetTestById(int id);
    const TestModel& GetTestByName(QString name);

private:
    QVector<TestModel> __models;
};

#endif // TESTMANAGER_HPP
