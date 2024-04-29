#include "packagetemplatemodel.hpp"

size_t PackageTemplateModel::__last_id = 0;

PackageTemplateModel::PackageTemplateModel(const QJsonObject& json) : __sections(json)
{
    /*if (json.contains("id"))
    {
        __id = json["id"].toInt();
    }
    else
    {
        __ErrorMsg("id");
        return;
    }*/
    __id = __last_id;
    __last_id++;
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

void PackageTemplateModel::SetSize(size_t size)
{
    if(size < __sections.GetTotalSize())
    {
        qDebug() << "Устанавливаемый размер меньше фактического ";
        return;
    }
    else
    {
        __size = size;
    }
}

size_t PackageTemplateModel::GetSize()
{
    return __size;
}

void PackageTemplateModel::AddSection(size_t pos, QJsonObject& json)
{
    if(pos + 1 > __size)
    {
        qDebug() << "Невозможно выполнить добавление, будет превышен допустимый размер пакета";
        return;
    }
    else
    {
        __sections.AddSection(pos, json);
    }
}

void PackageTemplateModel::ChangeSection(size_t pos, int package_zone_id, int start_position, int size_section)
{
    if(pos > __size)
    {
        qDebug() << "Невозможно выполнить изменение, превышен допустимый размер пакета";
        return;
    }
    else
    {
        __sections.ChangeSection(pos, package_zone_id, start_position, size_section);
    }
}

void PackageTemplateModel::DeleteSection(size_t pos)
{
    if(pos > __size)
    {
        qDebug() << "Невозможно выполнить удаление, превышен допустимый размер пакета";
        return;
    }
    else
    {
        __sections.DeleteSection(pos);
    }
}
void PackageTemplateModel::ConstructFromJson(const QJsonObject& json)
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

    __sections.ConstructFromJson(json);

}

QJsonObject PackageTemplateModel::DumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<int>(__id);
    json["name"] = __name;
    json["size"] = static_cast<int>(__size);
    json["sections"] = __sections.DumpToJson();
    json["description"] = __description;
    return json;
}

void PackageTemplateModel::SetDescriotion(QString description)
{
    __description = description;
}

QString PackageTemplateModel::GetDescription()
{
    return __description;
}
