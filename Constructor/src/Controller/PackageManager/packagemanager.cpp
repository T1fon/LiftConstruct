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

PackageManager& PackageManager::getInstance(const QJsonObject& json)
{
    static PackageManager instance(json);
    return instance;
}

void PackageManager::constructFromJson(const QJsonObject& json)
//нужно ли чистить вектор ?
{
    if(json.contains("packages"))
    {
        __models.clear();
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
QJsonArray PackageManager::dumpToJson()
{
    QJsonArray array;
    for(auto it = __models.begin(); it != __models.end(); ++it)
    {
        array.append(it->dumpToJson());

    }

    return array;
}
const PackageModel& PackageManager::returnById(const size_t& id)
{
    for ( auto& model : __models)
    {
        if (model.getId() == id)
        {
            return model;
        }
    }

    throw std::runtime_error("PackageModel with given id not found");
}

const PackageModel& PackageManager::returnByName(const QString& name)
{
    for ( auto& model : __models)
    {
        if (model.getName() == name)
        {
            return model;
        }
    }

    throw std::runtime_error("PackageModel with given name not found");
}
