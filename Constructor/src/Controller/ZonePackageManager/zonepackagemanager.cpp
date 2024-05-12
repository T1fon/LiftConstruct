#include "zonepackagemanager.hpp"

ZonePackageManager::ZonePackageManager(const QJsonObject& json)
{
    if(json.contains("package_zones"))
    {
        QJsonArray packages_array = json["package_zones"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.emplace_back(ZonePackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля packages";
        return;
    }
}

QVector<QString> ZonePackageManager::getAllNames()
{
    QVector<QString> names;
    for(auto& model: __models)
    {
        names.emplace_back(model.name());
    }
    return names;
}
ZonePackageModel& ZonePackageManager::getModel(const size_t& id)
{
    if(id >= __models.size())
    {
        throw std::invalid_argument("Invalid Id");
    }
    return __models[id];
}
ZonePackageModel& ZonePackageManager::getModel(const QString& name)
{
    for(ZonePackageModel& model: __models)
    {
        if(model.name() == name)
        {
            return model;
        }
    }
    throw std::invalid_argument("no name " + name.toStdString());
}
void ZonePackageManager::changeElement(const size_t& id, const QString& name, const QColor& color)
{
    if(id >= __models.size())
    {
        throw std::invalid_argument("Invalid Id");
    }
    __models[id].setColor(color);
    __models[id].setName(name);
    emit modelChanged(id);
}
void ZonePackageManager::changeElement(const QString& name, const QColor& color)
{
    bool flag = false;
    for(auto& model: __models)
    {
        if(model.name() == name)
        {
            flag = true;
            model.setColor(color);
            emit modelChanged(model.id());
            break;
        }
    }
    if(flag == false)
    {
        throw std::invalid_argument("no name " + name.toStdString());
    }
}
void ZonePackageManager::deleteElement(const size_t& id)
{
    if(id >= __models.size())
    {
        throw std::invalid_argument("Invalid Id");
    }
    __models.erase(__models.begin() + id);
    emit modelDeleted(__models.size());
}
void ZonePackageManager::deleteElement (const QString& name)
{
    bool found = false;
    for (auto it = __models.begin(); it != __models.end(); ++it) {
        if (it->name() == name)
        {
            __models.erase(it);
            emit modelDeleted(__models.size());
            found = true;
            break;
        }
    }
    if (found == false)
    {
        throw std::invalid_argument("no name " + name.toStdString());
    }
}
void ZonePackageManager::addElement(const QString& name, const QColor& color)
{
    __models.emplace_back(ZonePackageModel(name, color));
    emit modelAdded(__models.size());
}

void ZonePackageManager::constructFromJson(const QJsonObject& json)
{
    if(json.contains("package_zones"))
    {
        QJsonArray packages_array = json["package_zones"].toArray();

        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            __models.emplace_back(ZonePackageModel(buf_json));
        }
    }
    else
    {
        qDebug() << "json не содержит поля packages";
        return;
    }
}

QJsonObject ZonePackageManager::dumpToJson()
{
    QJsonObject models_json;
    QJsonArray array;
    QJsonObject one_model;
    for(auto& model : __models)
    {
        one_model = model.toJsonObject();
        array.append(one_model);
    }
    models_json["package_tempalte"] = array;
    return models_json;
}