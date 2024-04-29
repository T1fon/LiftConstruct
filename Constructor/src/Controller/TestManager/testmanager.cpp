#include "testmanager.hpp"

TestManager::TestManager(const QJsonObject& json)
{
    if(json.contains("tests"))
    {
        QJsonArray tests_array = json["tests"].toArray();

        for(const auto& item : tests_array)
        {
            QJsonObject buf_json = item.toObject();
            __models.emplace_back(TestModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля sequence_of_packages";
        return;
    }
}
void TestManager::ConstructFromJson(const QJsonObject& json)
{
    if(json.contains("tests"))
    {
        QJsonArray tests_array = json["tests"].toArray();

        for(const auto& item : tests_array)
        {
            QJsonObject buf_json = item.toObject();
            __models.emplace_back(TestModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля sequence_of_packages";
        return;
    }
}
QJsonObject TestManager::DumpFromJson()
{
    QJsonArray array;
    for(auto it = __models.begin(); it != __models.end(); ++it)
    {
        array.append(it->DumpToJson());
    }

    QJsonObject json;
    json["tests"] = array;

    return json;
}
const TestModel& TestManager::GetTestById(int id)
{
    for ( auto& model : __models)
    {
        if (model.GetId() == id)
        {
            return model;
        }
    }
    throw std::runtime_error("TestModel with given id not found");
}
const TestModel& TestManager::GetTestByName(QString name)
{
    for ( auto& model : __models)
    {
        if (model.GetName() == name)
        {
            return model;
        }
    }
    throw std::runtime_error("TestModel with given name not found");
}