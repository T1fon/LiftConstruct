#include "sectionmanager.hpp"

SectionManager::SectionManager(const QJsonObject& json)
{
    if(json.empty())
    {
        __sections.clear();
        __total_size = 0;
    }
    else
    {
        if (json.contains("sections"))
        {
            QJsonArray array = json["sections"].toArray();

            for( const QJsonValue& one_section_box: array)
            {
                QJsonObject one_section = one_section_box.toObject();
                __sections.emplace_back(SectionModel(one_section));
            }
        }
        else
            __errorMsg("sections");
        __total_size = __sections.size();
    }
}
SectionManager::SectionManager(const SectionManager& other)
    : QObject(other.parent()), __sections(other.__sections), __total_size(other.__total_size)
{
}
SectionManager& SectionManager::operator=(const SectionManager& other)
{
    if (this != &other)
    {
        __sections = other.__sections;
        __total_size = other.__total_size;
    }
    return *this;
}

void SectionManager::__errorMsg(QString target)
{
    qDebug() << "Ошибка, json не не содержит поле " << target;
}

void SectionManager::addSection(const size_t& pos, const QJsonObject& json)
{
    __sections.emplace_back(SectionModel(json));
    __total_size = __sections.size();
    emit SectionAdded(__total_size);
}

void SectionManager::addSection(const size_t& package_zone_id, const size_t& start_postition, const size_t& size_section)
{
    __sections.emplace_back(SectionModel(package_zone_id, start_postition, size_section));
    __total_size = __sections.size();
    emit SectionAdded(__total_size);
}

void SectionManager::changeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position,
                                   const size_t& size_section)
{
    if(pos < __total_size)
    {
        SectionModel& model = getModel(pos);
        model.setPackageZoneId(package_zone_id);
        model.setStartPosition(start_position);
        model.setSizeStation(size_section);
    }
    else
    {
        qDebug() << "total_size > pos ";
        return;
    }
}
//или здесь искать по id ?
size_t SectionManager::searchSection(const size_t& pos)
{
    try
    {
        __sections[pos].getPackageZoneId();
        return pos;
    }
    catch (const std::out_of_range&)
    {
        return -1;
    }

}

const QVector<SectionModel>& SectionManager::GetSections() const
{
    return __sections;
}

void SectionManager::deleteSection(const size_t& pos)
{
    if(pos < __total_size)
    {
        __sections.remove(pos);
        __total_size = __sections.size();
        emit SectionDeleted(__sections.size() - 1);
    }
    else
    {
        qDebug() << "total_size > pos ";
        return;
    }
}

QJsonArray SectionManager::dumpToJson()
{
    QJsonArray array;
    QJsonObject one_section;
    for(auto& section : __sections)
    {
        one_section = section.toJson();
        array.append(one_section);
    }
    return array;
}

void SectionManager::constructFromJson(const QJsonObject& json)
{
    if (json.contains("sections"))
    {
        QJsonArray array = json["sections"].toArray();

        for( const QJsonValue& one_section_box: array)
        {
            QJsonObject one_section = one_section_box.toObject();
            __sections.emplace_back(SectionModel(one_section));
        }
    }
    else
        __errorMsg("sections");
    if (json.contains("size"))
    {
        __total_size = json["size"].toInt();
    }
    else
        __errorMsg("size");
}

int SectionManager::getTotalSize()
{
    return __total_size;
}

SectionModel& SectionManager::getModel(const size_t& pos)
{
    try
    {
        return __sections[pos];
    }
    catch(const std::out_of_range&)
    {
        qDebug() << "pos > size";
    }
}

void SectionManager::setModel(const size_t& pos, const SectionModel& model)
{
    __sections[pos] = model;
}
