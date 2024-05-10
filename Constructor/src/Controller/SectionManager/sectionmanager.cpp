#include "sectionmanager.hpp"

SectionManager::SectionManager(const QJsonObject& json)
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
        __ErrorMsg("sections");
    __total_size = __sections.size();
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

void SectionManager::__ErrorMsg(QString target)
{
    qDebug() << "Ошибка, json не не содержит поле " << target;
}

void SectionManager::AddSection(const size_t& pos, const QJsonObject& json)
{
    __sections.emplace_back(SectionModel(json));
    __total_size = __sections.size();
    emit SectionAdded(__total_size);
}

void SectionManager::ChangeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position,
                                   const size_t& size_section)
{
    if(pos < __total_size)
    {
        SectionModel& model = getModel(pos);
        model.SetPackageZoneId(package_zone_id);
        model.SetStartPosition(start_position);
        model.SetSizeStation(size_section);
    }
    else
    {
        qDebug() << "total_size > pos ";
        return;
    }
}
//или здесь искать по id ?
size_t SectionManager::SearchSection(const size_t& pos)
{
    try
    {
        __sections[pos].GetPackageZoneId();
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

void SectionManager::DeleteSection(const size_t& pos)
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

QJsonObject SectionManager::DumpToJson()
{
    QJsonObject sections_json;
    QJsonArray array;
    QJsonObject one_section;
    for(auto& section : __sections)
    {
        one_section = section.toJson();
        array.append(one_section);
    }
    sections_json["sections"] = array;
    return sections_json;
}

void SectionManager::ConstructFromJson(const QJsonObject& json)
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
        __ErrorMsg("sections");
    if (json.contains("size"))
    {
        __total_size = json["size"].toInt();
    }
    else
        __ErrorMsg("size");
}

int SectionManager::GetTotalSize()
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
