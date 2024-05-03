#include "packagetemplatemanager.hpp"

PackageTemplateManager::PackageTemplateManager(const QJsonObject& json)
{
    if(json.contains("package_tempalte"))
    {
        QJsonArray array = json["package_tempalte"].toArray();

        for( const QJsonValue& one_model: array)
        {
            QJsonObject one_object = one_model.toObject();
            __models.emplace_back(PackageTemplateModel(one_object));
        }
    }
    else
    {
        qDebug() << "Ошибка чтения json";
        return;
    }
}

void PackageTemplateManager::ConstructFromJson(const QJsonObject& json)
{
    if(json.contains("package_tempalte"))
    {
        QJsonArray array = json["package_tempalte"].toArray();

        for( const QJsonValue& one_model: array)
        {
            QJsonObject one_object = one_model.toObject();
            __models.emplace_back(PackageTemplateModel(one_object));
        }
    }
    else
    {
        qDebug() << "Ошибка чтения json";
        return;
    }
}

QJsonObject PackageTemplateManager::DumpToJson()
{
    QJsonObject models_json;
    QJsonArray array;
    QJsonObject one_model;
    for(auto& model : __models)
    {
        one_model = model.DumpToJson();
        array.append(one_model);
    }
    models_json["package_tempalte"] = array;
    return models_json;
}

void PackageTemplateManager::AddSample(const QJsonObject& json)
{
    QJsonObject modifiedJson = json;

    if(modifiedJson.contains("id"))
    {
        modifiedJson.remove("id");
    }
    __models.emplace_back(PackageTemplateModel(modifiedJson));
}

void PackageTemplateManager::ChangeElement(const QJsonObject& json)
{
    for(auto& model : __models)
    {

    }
}
