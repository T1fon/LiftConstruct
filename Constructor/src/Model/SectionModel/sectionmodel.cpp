#include "sectionmodel.hpp"

SectionModel::SectionModel(const size_t& package_zone_id, const size_t& start_position, const size_t& size_section)
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
    if(json.empty())
    {
        __package_zone_id = 0;
        __start_position = 0;
        __size_section = 0;
    }
    else
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

}

void SectionModel::__ErrorMsg(QString target)
{
     qDebug() << "Ошибка, json не считал строчку " << target;
}

void SectionModel::setPackageZoneId(const size_t& package_zone_id)
{
    __package_zone_id = package_zone_id;
}

size_t& SectionModel::getPackageZoneId()
{
    return __package_zone_id;
}

void SectionModel::setStartPosition(const size_t& start_position)
{
    __start_position = start_position;
}

size_t& SectionModel::getStartPosition()
{
    return __start_position;
}

void SectionModel::setSizeStation(const size_t& size_section)
{
    __size_section = size_section;
}

size_t& SectionModel::getSizeStation()
{
    return __size_section;
}
QJsonObject SectionModel::toJson()
{
    QJsonObject json;
    json["package_zone_id"] = static_cast<int>(__package_zone_id);
    json["start_position"] = static_cast<int>(__start_position);
    json["size_section"] = static_cast<int>(__size_section);
    return json;
}

void SectionModel::constructFromJson(const QJsonObject& json)
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
