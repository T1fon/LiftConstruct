#include "sectionmodel.hpp"

SectionModel::SectionModel(int package_zone_id, int start_position, int size_section)
{
    __package_zone_id = package_zone_id;
    __start_position = start_position;
    __size_section = size_section;
}

SectionModel::SectionModel(const SectionModel& other)
{
    __package_zone_id = other.__package_zone_id;
    __start_position = other.__start_position;
    __size_section = other.__size_section;
}

SectionModel::SectionModel(const QJsonObject& json)
{
    if (json.contains("package_zone_id"))
    {
        __package_zone_id = json["package_zone_id"].toInt();
    }
    else
    {
        __ErrorMsg("package_zone_id");
        return;
    }
    if (json.contains("start_position"))
    {
        __start_position = json["start_position"].toInt();
    }
    else
    {
        __ErrorMsg("start_position");
        return;
    }
    if (json.contains("size_section"))
    {
        __size_section = json["size_section"].toInt();
    }
    else
    {
        __ErrorMsg("size_section");
        return;
    }

}

void SectionModel::__ErrorMsg(QString target)
{
     qDebug() << "Ошибка, json не считал строчку " << target;
}

void SectionModel::SetPackageZoneId(int package_zone_id)
{
    __package_zone_id = package_zone_id;
}

int SectionModel::GetPackageZoneId()
{
    return __package_zone_id;
}

void SectionModel::SetStartPosition(int start_position)
{
    __start_position = start_position;
}

int SectionModel::GetStartPosition()
{
    return __start_position;
}

void SectionModel::SetSizeStation(int size_section)
{
    __size_section = size_section;
}

int SectionModel::GetSizeStation()
{
    return __size_section;
}
QJsonObject SectionModel::toJson()
{
    QJsonObject json;
    json["package_zone_id"] = __package_zone_id;
    json["start_position"] = __start_position;
    json["size_section"] = __size_section;
    return json;
}

void SectionModel::ConstructFromJson(const QJsonObject& json)
{
    if (json.contains("package_zone_id"))
    {
        __package_zone_id = json["package_zone_id"].toInt();
    }
    else
    {
        __ErrorMsg("package_zone_id");
        return;
    }
    if (json.contains("start_position"))
    {
        __start_position = json["start_position"].toInt();
    }
    else
    {
        __ErrorMsg("start_position");
        return;
    }
    if (json.contains("size_section"))
    {
        __size_section = json["size_section"].toInt();
    }
    else
    {
        __ErrorMsg("size_section");
        return;
    }
}
