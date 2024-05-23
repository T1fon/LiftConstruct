#include "testmodel.hpp"
size_t TestModel::__last_id = 0;

TestModel::TestModel(const QJsonObject& json): __sequence_of_packages(json)
{
    if(json.contains("id"))
    {
        __id = json["id"].toInteger(__last_id);
        if(__last_id < __id){__last_id = __id;}
    }
    else
    {
        qDebug() << "остутствует поле id";
        return;
    }
    if(json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "остутствует поле name";
        return;
    }
    if(json.contains("station_id"))
    {
        __station_id = json["station_id"].toInt();
    }
    else
    {
        qDebug() << "остутствует поле station_id";
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
TestModel::TestModel(const QString& name, const size_t& station_id,
                     const QVector<SequenceOfPackageModel>& sequence_of_packages, const QString& description) : __sequence_of_packages(sequence_of_packages)
{
    __id = __last_id;
    __last_id++;
    __name = name;
    __station_id = station_id;
    __description = description;
}
void TestModel::setName(const QString& name)
{
    __name = name;
}
void TestModel::setStationId(const size_t& station_id)
{
    __station_id = station_id;
}
void TestModel::setSequenceOfPackages(const QVector<SequenceOfPackageModel>& sequence_of_packages)
{
    __sequence_of_packages.setPackages(sequence_of_packages);
}
void TestModel::setDescription(const QString& description)
{
    __description = description;
}
size_t TestModel::getId()
{
    return __id;
}
QString TestModel::getName()
{
    return __name;
}
size_t TestModel::getStationId()
{
    return __station_id;
}
QVector<SequenceOfPackageModel> TestModel::getSequenceOfPackagesById(const size_t& id)
{
    return __sequence_of_packages.returnByPackageId(id);
}
SequenceOfPackageModel TestModel::getSequenceOfPackagesModelByPos(const size_t& pos)
{
    return __sequence_of_packages.returnByPosition(pos);
}
QString TestModel::getDescription()
{
    return __description;
}
void TestModel::constructFromJson(const QJsonObject& json)
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

        __sequence_of_packages.constructFromJson(json["sequence_of_packages"].toObject());
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
QJsonObject TestModel::dumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<int>(__id);
    json["name"] = __name;
    json["station_id"] = static_cast<int>(__station_id);
    // Получаем JSON-массив для sequence_of_packages
    QJsonValue sequenceValue = __sequence_of_packages.dumpToJson();

    json["sequence_of_packages"] = __sequence_of_packages.dumpToJson();
    json["description"] = __description;

    return json;
}
