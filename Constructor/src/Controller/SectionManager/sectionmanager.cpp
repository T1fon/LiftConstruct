#include "sectionmanager.hpp"

SectionManager::SectionManager(const QJsonObject& json) : __buf_model(0, 0, 0)
{
    if (json.contains("sections"))
    {
        QJsonArray array = json["sections"].toArray();

        for( const QJsonValue& one_section_box: array)
        {
            QJsonObject one_section = one_section_box.toObject();
            __buf_model.ConstructFromJson(one_section);
            __sections.append(__buf_model);
        }
    }
    else
        __ErrorMsg("sections");
    __total_size = __sections.size();
}

void SectionManager::__ErrorMsg(QString target)
{
    qDebug() << "Ошибка, json не не содержит поле " << target;
}

void SectionManager::AddSection(size_t pos, QJsonObject& json)
{

    __buf_model.ConstructFromJson(json);
    __sections.append(__buf_model);
    emit SectionChanged(__sections.size() - 1);
    __total_size = __sections.size();
}

void SectionManager::ChangeSection(size_t pos, int package_zone_id, int start_position, int size_section)
{
    if(pos < __total_size)
    {
        __sections[pos].SetPackageZoneId(package_zone_id);
        __sections[pos].SetStartPosition(start_position);
        __sections[pos].SetSizeStation(size_section);
        emit SectionChanged(pos);
    }
    else
    {
        qDebug() << "total_size > pos ";
        return;
    }
}

size_t SectionManager::SearchSection(size_t pos)
{
    if (pos < __total_size)
    {
        try
        {

            if (pos < __sections.size())
            {
                return pos;
            }
            else
            {
                return -1;
            }
        }
        catch (const std::out_of_range&)
        {
            return -1;
        }
    }
    else
    {
        qDebug() << "total_size > pos";
        return -1;
    }
}

const QVector<SectionModel>& SectionManager::GetSections() const
{
    return __sections;
}

void SectionManager::DeleteSection(size_t pos)
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
            __buf_model.ConstructFromJson(one_section);
            __sections.append(__buf_model);
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
