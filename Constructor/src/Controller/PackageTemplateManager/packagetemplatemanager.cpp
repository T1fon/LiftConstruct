#include "packagetemplatemanager.hpp"

PackageTemplateManager::PackageTemplateManager(const QJsonObject& json)
{
    if(json.empty())
    {
        __models.clear();
    }
    else
    {
        if (json.contains("package_template"))
        {
            QJsonArray array = json["package_template"].toArray();
            qDebug() << "Found package_template, count:" << array.size();

            for (const QJsonValue& one_model : array)
            {
                QJsonObject one_object = one_model.toObject();
                qDebug() << "Adding model:" << one_object;
                __models.emplace_back(PackageTemplateModel(one_object));
            }
        } else
        {
            qDebug() << "Ошибка чтения json в PackageTemplateManager: package_template not found";
            return;
        }
    }
}
PackageTemplateManager::PackageTemplateManager(){}

void PackageTemplateManager::constructFromJson(const QJsonObject& json)
{
    __models.clear();
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

QJsonArray PackageTemplateManager::DumpToJson()
{

    QJsonArray array;
    QJsonObject one_model;
    for(auto& model : __models)
    {
        one_model = model.dumpToJson();
        qDebug() << one_model;
        array.append(one_model);
    }

    return array;
}

void PackageTemplateManager::addSample(const QJsonObject& json)
{
    QJsonObject modifiedJson = json;

    if(modifiedJson.contains("id"))
    {
        modifiedJson.remove("id");
    }
    __models.emplace_back(PackageTemplateModel(modifiedJson));
    emit PackageTemplateAdded(__models.size());
}

void PackageTemplateManager::changeElement(const QString& name, const size_t& size, const QString& description)
{
    if(size == 0 && description == "")
    {
        qDebug() << "Нет данных для изменения";
        return;
    }
    for(auto& model : __models)
    {
        if(model.getName() == name)
        {
            if(size != 0)
            {
                model.setSize(size);
            }
            if(description != "")
            {
                model.setDescriotion(description);
            }
            emit PackageTempalteChange(model.getId());
            break;
        }
    }
}
void PackageTemplateManager::changeElement(const size_t& id, const QString& name,
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
                model.setName(name);
            }
            if(size != 0)
            {
                model.setSize(size);
            }
            if(description != "")
            {
                model.setDescriotion(description);
            }
            emit PackageTempalteChange(model.getId());
            break;
        }
    }
}

void PackageTemplateManager::changeElement(const QString& name,
                                            const size_t& pos_section,const size_t& package_sone_id,
                                           const size_t& start_postition, const size_t& size_section)
{
    if( pos_section == -1 && package_sone_id == 0 && start_postition == 0 && size_section == 0)
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
        if(model.getName() == name)
        {

            SectionManager manager = model.getSection();
            manager.changeSection(pos_section, package_sone_id, start_postition, size_section);
            emit PackageTempalteChange(model.getId());
            return;
        }
    }

}
void PackageTemplateManager::changeElement(const size_t& id,const size_t& pos_section,
                                           const size_t& package_sone_id, const size_t& start_postition, const size_t& size_section)
{
    if(pos_section == -1 && package_sone_id == 0 && start_postition == 0 && size_section == 0)
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
        if(model.getId() == id)
        {
            model.changeSection(pos_section, package_sone_id, start_postition, size_section);
            emit PackageTempalteChange(model.getId());
            return;
        }
    }

    qDebug() << "Неверный id";
    return;

}

void PackageTemplateManager::deleteElement(const size_t& id)
{
    for (auto it = __models.begin(); it != __models.end(); ++it) {
        if (it->getId() == id) {
            it = __models.erase(it);
            emit PackageTemplateDeleted(id);
            return;
        }
    }
}
void PackageTemplateManager::deleteElement(const QString& name)
{
    for (auto it = __models.begin(); it != __models.end(); ++it)
    {
        if (it->getName() == name) {
            size_t id = it->getId();
            it = __models.erase(it);
            emit PackageTemplateDeleted(id);
            return;
        }
    }
}

size_t PackageTemplateManager::getSize()
{
    return __models.size();
}

PackageTemplateModel& PackageTemplateManager::getModel(const size_t& id)
{
    for(auto& model : __models)
    {
        if(model.getId() == id)
            return model;
    }
    throw std::invalid_argument("no such id");
}
