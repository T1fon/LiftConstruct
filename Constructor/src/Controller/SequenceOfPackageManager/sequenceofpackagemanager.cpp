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
QJsonObject SequenceOfPackageManager::DumpToJson()
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
const SequenceOfPackageModel& ReturnByPosition(int position);
QVector<SequenceOfPackageModel> ReturnByPackageId(int package_id);
