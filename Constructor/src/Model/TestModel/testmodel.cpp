#include "testmodel.hpp"
size_t TestModel::__last_id = 0;

TestModel::TestModel(const QJsonObject& json)
{
    __id = __last_id;
    __last_id++;
    if(json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "остутствует поле name";
        __last_id--;
        return;
    }
    if(json.contains("station_id"))
    {
        __station_id = json["station_id"].toInt();
    }
    else
    {
        qDebug() << "остутствует поле station_id";
        __last_id--;
        return;
    }
    if(json.contains("sequence_of_packages"))
    {
        QJsonArray sequence_array = json["sequence_of_packages"].toArray();

        for(const auto& item : sequence_array)
        {
            const QJsonObject buf_json = item.toObject();
            __sequence_of_packages.emplace_back(SequenceOfPackageManager(buf_json));
        }
    }
    else
    {
        qDebug() << "остутствует поле sequence_of_packages";
        __last_id--;
        return;
    }
    if(json.contains("description"))
    {
        __description = json["description"].toString();
    }
    else
    {
        qDebug() << "остутствует поле description";
        __last_id--;
        return;
    }
}
TestModel::TestModel(QString name, int station_id,
                     QVector<SequenceOfPackageManager> sequence_of_packages = QVector<SequenceOfPackageManager>(), QString description = "")
{
    __id = __last_id;
    __last_id++;
    __name = name;
    __station_id = station_id;
    __sequence_of_packages = sequence_of_packages;
    __description = description;
}
void TestModel::SetName(QString name)
{
    __name = name;
}
void TestModel::SetStationId(int station_id)
{
    __station_id = station_id;
}
void TestModel::SetSequenceOfPackages(QVector<SequenceOfPackageManager> sequence_of_packages)
{
    __sequence_of_packages = sequence_of_packages;
}
void TestModel::SetDescription(QString description)
{
    __description = description;
}
int TestModel::GetId()
{
    return __id;
}
QString TestModel::GetName()
{
    return __name;
}
int TestModel::GetStationId()
{
    return __station_id;
}
QVector<SequenceOfPackageManager> TestModel::GetSequenceOfPackages()
{
    return __sequence_of_packages;
}
QString TestModel::GetDescription()
{
    return __description;
}
void TestModel::ConstructFromJson(const QJsonObject& json)
{
    //__id = __last_id;
    //__last_id++;
    if(json.contains("id"))
    {
        __id = json["id"].toInt();
    }
    else
    {
        qDebug() << "остутствует поле id";
        //__last_id--;
        return;
    }
    if(json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "остутствует поле name";
        //__last_id--;
        return;
    }
    if(json.contains("station_id"))
    {
        __station_id = json["station_id"].toInt();
    }
    else
    {
        qDebug() << "остутствует поле station_id";
        //__last_id--;
        return;
    }
    if(json.contains("sequence_of_packages"))
    {
        QJsonArray sequence_array = json["sequence_of_packages"].toArray();

        for(const auto& item : sequence_array)
        {
            const QJsonObject buf_json = item.toObject();
            __sequence_of_packages.emplace_back(SequenceOfPackageManager(buf_json));
        }
    }
    else
    {
        qDebug() << "остутствует поле sequence_of_packages";
        //__last_id--;
        return;
    }
    if(json.contains("description"))
    {
        __description = json["description"].toString();
    }
    else
    {
        qDebug() << "остутствует поле description";
        //__last_id--;
        return;
    }
}
QJsonObject TestModel::DumpToJson()
{
    QJsonObject json;
    json["id"] = __id;
    json["name"] = __name;
    json["station_id"] = __station_id;
    QJsonArray array;
    for(auto it = __sequence_of_packages.begin(); it != __sequence_of_packages.end(); ++it)
    {
        array.append(it->DumpToJson());

    }
    json["packages"] = array;
    json["description"] = __description;

    return json;
}
