#include "packagemanager.hpp"

PackageManager::PackageManager(const QJsonObject& json)
{
    if(json.contains("packages"))
    {
        QJsonArray packages_array = json["packages"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.emplace_back(PackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля packages";
        return;
    }
}
void PackageManager::ConstructFromJson(const QJsonObject& json)
//нужно ли чистить вектор ?
{
    if(json.contains("packages"))
    {
        QJsonArray packages_array = json["packages"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.emplace_back(PackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля packages";
        return;
    }
}
QJsonObject PackageManager::DumpFromJson()
{
    QJsonArray array;
    for(auto it = __models.begin(); it != __models.end(); ++it)
    {
        array.append(it->DumpToJson());

    }
    QJsonObject json;
    json["packages"] = array;

    return json;
}
const PackageModel& PackageManager::ReturnById(const size_t& id)
{
    for ( auto& model : __models)
    {
        if (model.GetId() == id)
        {
            return model;
        }
    }

    throw std::runtime_error("PackageModel with given id not found");
}

const PackageModel& PackageManager::ReturnByName(const QString& name)
{
    for ( auto& model : __models)
    {
        if (model.GetName() == name)
        {
            return model;
        }
    }

    throw std::runtime_error("PackageModel with given name not found");
}
