#include "sequenceofpackagemanager.hpp"

SequenceOfPackageManager::SequenceOfPackageManager(const QJsonObject& json)
{
    if(json.contains("sequence_of_packages"))
    {
        QJsonArray packages_array = json["sequence_of_packages"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.insert(SequenceOfPackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля sequence_of_packages";
        return;
    }
}

SequenceOfPackageManager::SequenceOfPackageManager(const QVector<SequenceOfPackageModel>& models)
{
    for(auto& model: models)
    {
        __models.insert(model);
    }
}
void SequenceOfPackageManager::ConstructFromJson(const QJsonObject& json)
{
    if(json.contains("sequence_of_packages"))
    {
        QJsonArray packages_array = json["sequence_of_packages"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.insert(SequenceOfPackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля sequence_of_packages";
        return;
    }
}
QJsonArray SequenceOfPackageManager::DumpToJson()
{
    QJsonArray array;
    for(auto it = __models.begin(); it != __models.end(); ++it)
    {
        array.append(it->DumpToJson());
    }

    return array;
}
SequenceOfPackageModel SequenceOfPackageManager::ReturnByPosition(const size_t& position)
{
    for ( auto& model : __models)
    {
        if (model.GetPosition() == position)
        {
            return model;
        }
    }
    throw std::runtime_error("SequenceOfPackageModel with given id not found");
}
QVector<SequenceOfPackageModel> SequenceOfPackageManager::ReturnByPackageId(const size_t& package_id)
{
    QVector<SequenceOfPackageModel> res;
    for ( auto& model : __models)
    {
        if (model.GetPackageId() == package_id)
        {
            res.push_back(model);
        }
    }
    return res;
}
void SequenceOfPackageManager::setPackages(const QVector<SequenceOfPackageModel>& sequence_of_packages)
{
    for(auto& model: sequence_of_packages)
    {
        __models.insert(model);
    }
}
