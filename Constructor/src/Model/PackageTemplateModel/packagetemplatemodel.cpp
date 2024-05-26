#include "packagetemplatemodel.hpp"

size_t PackageTemplateModel::__last_id = 0;

PackageTemplateModel::PackageTemplateModel(const QJsonObject& json) : __sections(json)
{
    if(json.empty())
    {
        __last_id = 0;
        __id = 0;
        __description.clear();
        __name.clear();
    }
    if(json.contains("id"))
    {
        __id = json["id"].toInteger(__last_id);
        if(__last_id < __id){__last_id = __id;};
    }
    else
    {
        __ErrorMsg("id");
        return;
    }

    if (json.contains("size"))
    {
        __size = json["size"].toInt();
    }
    else
    {
        __ErrorMsg("size");
        return;
    }
    if (json.contains("description"))
    {
        __description = json["description"].toString();
    }
    else
    {
        __ErrorMsg("description");
        return;
    }
    if (json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        __ErrorMsg("name");
        return;
    }
}
void PackageTemplateModel::__ErrorMsg(QString target)
{
    qDebug() << "Ошибка, json не не содержит поле " << target;
}

void PackageTemplateModel::setSize(const size_t& size)
{
    if(size < __sections.getTotalSize())
    {
        qDebug() << "Устанавливаемый размер меньше фактического ";
        return;
    }
    else
    {
        __size = size;
    }
}

const size_t& PackageTemplateModel::getSize()
{
    return __size;
}

void PackageTemplateModel::addSection(const size_t& pos, const QJsonObject& json)
{
    if(pos + 1 > __size)
    {
        qDebug() << "Невозможно выполнить добавление, будет превышен допустимый размер пакета";
        return;
    }
    else
    {
        __sections.addSection(pos, json);
    }
}

void PackageTemplateModel::addSection(const size_t& pos,const size_t& package_zone_id, const size_t& start_position,
                                      const size_t& size_section)
{
    if(pos + 1 > __size)
    {
        qDebug() << "Невозможно выполнить добавление, будет превышен допустимый размер пакета";
        return;
    }
    __sections.addSection(package_zone_id, start_position, size_section);
}

void PackageTemplateModel::changeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position,
                                         const size_t& size_section)
{
    if(pos < __size)
    {
        __sections.changeSection(pos,package_zone_id,start_position, size_section);
    }
    else
    {
        qDebug() << "Выбрана несуществующая позиция";
        return;
    }
}
void PackageTemplateModel::changeSection(const size_t& size, const QString& description, const QString& name)
{
    try
    {
        setSize(size);
        setDescriotion(description);
        setName(name);
    }
    catch(std::bad_function_call)
    {
        qDebug() << "Ошибка при изменении";
        return;
    }
}
void PackageTemplateModel::changeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position, const size_t& size_section,
                   const size_t& size, const QString& description, const QString& name)
{
    if(pos < __size)
    {
        __sections.changeSection(pos,package_zone_id,start_position, size_section);
    }
    else
    {
        qDebug() << "Выбрана несуществующая позиция";
        return;
    }
    try
    {
        setSize(size);
        setDescriotion(description);
        setName(name);
    }
    catch(std::bad_function_call)
    {
        qDebug() << "Ошибка при изменении";
        return;
    }

}


void PackageTemplateModel::deleteSection(const size_t& pos)
{
    if(pos > __size)
    {
        qDebug() << "Невозможно выполнить удаление, превышен допустимый размер пакета";
        return;
    }
    else
    {
        __sections.deleteSection(pos);
    }
}
void PackageTemplateModel::constructFromJson(const QJsonObject& json)
{
    if (json.contains("id"))
    {
        __id = json["id"].toInt();
    }
    else
    {
        __ErrorMsg("id");
        return;
    }
    if (json.contains("size"))
    {
        __size = json["size"].toInt();
    }
    else
    {
        __ErrorMsg("size");
        return;
    }
    if (json.contains("description"))
    {
        __description = json["description"].toString();
    }
    else
    {
        __ErrorMsg("description");
        return;
    }
    if (json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        __ErrorMsg("name");
        return;
    }

    __sections.constructFromJson(json);

}

QJsonObject PackageTemplateModel::dumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<int>(__id);
    json["name"] = __name;
    json["size"] = static_cast<int>(__size);
    json["sections"] = __sections.dumpToJson();
    json["description"] = __description;
    return json;
}

void PackageTemplateModel::setDescriotion(const QString& description)
{
    __description = description;
}

QString& PackageTemplateModel::getDescription()
{
    return __description;
}
SectionManager& PackageTemplateModel::getSection()
{
    return __sections;
}
void PackageTemplateModel::setSection(const SectionManager& section)
{
    __sections = section;
}
void PackageTemplateModel::setName(const QString& name)
{
    __name = name;
}
QString& PackageTemplateModel::getName()
{
    return __name;
}
size_t& PackageTemplateModel::getId()
{
    return __id;
}
