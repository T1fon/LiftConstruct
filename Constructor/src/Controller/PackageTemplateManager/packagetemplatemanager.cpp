#include "packagetemplatemanager.hpp"

PackageTemplateManager::PackageTemplateManager(const QJsonObject& json)
{
    if(json.contains("package_tempalte"))
    {
        QJsonArray array = json["package_tempalte"].toArray();

        for( const QJsonValue& one_model: array)
        {
            QJsonObject one_object = one_model.toObject();
            __models.emplace_back(PackageTemplateModel(one_object));
        }
    }
    else
    {
        qDebug() << "Ошибка чтения json";
        return;
    }
}

void PackageTemplateManager::ConstructFromJson(const QJsonObject& json)
{
    if(json.contains("package_tempalte"))
    {
        QJsonArray array = json["package_tempalte"].toArray();

        for( const QJsonValue& one_model: array)
        {
            QJsonObject one_object = one_model.toObject();
            __models.emplace_back(PackageTemplateModel(one_object));
        }
    }
    else
    {
        qDebug() << "Ошибка чтения json";
        return;
    }
}

QJsonObject PackageTemplateManager::DumpToJson()
{
    QJsonObject models_json;
    QJsonArray array;
    QJsonObject one_model;
    for(auto& model : __models)
    {
        one_model = model.DumpToJson();
        array.append(one_model);
    }
    models_json["package_tempalte"] = array;
    return models_json;
}

void PackageTemplateManager::AddSample(const QJsonObject& json)
{
    QJsonObject modifiedJson = json;

    if(modifiedJson.contains("id"))
    {
        modifiedJson.remove("id");
    }
    __models.emplace_back(PackageTemplateModel(modifiedJson));
    PackageTemplateAdded(__models.size());
}

void PackageTemplateManager::ChangeElement(const QString& name, const size_t& size, const QString& description)
{
    if(size == 0 && description == "")
    {
        qDebug() << "Нет данных для изменения";
        return;
    }
    for(auto& model : __models)
    {
        if(model.GetName() == name)
        {
            if(size != 0)
            {
                model.SetSize(size);
            }
            if(description != "")
            {
                model.SetDescriotion(description);
            }
            PackageTempalteChange(model.getId());
            break;
        }
    }
}
void PackageTemplateManager::ChangeElement(const size_t& id, const QString& name,
                                           const size_t& size, const QString& description)
{
    if(name == "" && size == 0 && description == "")
    {
        qDebug() << "Нет данных для изменения";
        return;
    }
    for(auto& model : __models)
    {
        if(model.getId() == id)
        {
            if(name != "")
            {
                model.SetName(name);
            }
            if(size != 0)
            {
                model.SetSize(size);
            }
            if(description != "")
            {
                model.SetDescriotion(description);
            }
            PackageTempalteChange(model.getId());
            break;
        }
    }
}

void PackageTemplateManager::ChangeElement(const QString& name, const size_t& size, const QString& description,
                                            const size_t& pos_section,const size_t& package_sone_id,
                                           const size_t& start_postition, const size_t& size_section)
{
    if(size == 0 && description == "" && pos_section == -1 && package_sone_id == 0 && start_postition == 0 && size_section == 0)
    {
        qDebug() << "Нет данных для изменения";
        return;
    }
    if(pos_section == -1)
    {
        qDebug() << "Не выбрана секция для изменения";
        return;
    }
    for(auto& model : __models)
    {
        if(model.GetName() == name)
        {
            if(size != 0)
            {
                model.SetSize(size);
            }
            if(description != "")
            {
                model.SetDescriotion(description);
            }
            SectionManager manager = model.getSection();
            manager.ChangeSection(pos_section, package_sone_id, start_postition, size_section);
            PackageTempalteChange(model.getId());
            return;
        }
    }

}
void PackageTemplateManager::ChangeElement(const size_t& id, const QString& name, const size_t& size,
                                           const QString& description, const size_t& pos_section,
                                           const size_t& package_sone_id, const size_t& start_postition, const size_t& size_section)
{
    if(name == "" && size == 0 && description == ""
        && pos_section == -1 && package_sone_id == 0 && start_postition == 0 && size_section == 0)
    {
        qDebug() << "Нет данных для изменения";
        return;
    }
    if(pos_section == -1)
    {
        qDebug() << "Не выбрана секция для изменения";
        return;
    }
    for(auto& model : __models)
    {
        if(model.GetName() == name)
        {
            if(size != 0)
            {
                model.SetSize(size);
            }
            if(description != "")
            {
                model.SetDescriotion(description);
            }
            if(name != "")
            {
                model.SetName(name);
            }
            SectionManager manager = model.getSection();
            manager.ChangeSection(pos_section, package_sone_id, start_postition, size_section);
            PackageTempalteChange(model.getId());
            return;
        }
    }

}

void PackageTemplateManager::DeleteElement(const size_t& id)
{
    for (auto it = __models.begin(); it != __models.end(); ++it) {
        if (it->getId() == id) {
            it = __models.erase(it);
            emit PackageTemplateDeleted(id);
            return;
        }
    }
}
void PackageTemplateManager::DeleteElement(const QString& name)
{
    for (auto it = __models.begin(); it != __models.end(); ++it)
    {
        if (it->GetName() == name) {
            size_t id = it->getId();
            it = __models.erase(it);
            emit PackageTemplateDeleted(id);
            return;
        }
    }
}
