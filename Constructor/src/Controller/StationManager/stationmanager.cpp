#include "stationmanager.hpp"

StationManager::StationManager(const QJsonObject& json)
{
    if (json.contains("station"))
    {
        QJsonArray array = json["station"].toArray();

        for( const QJsonValue& one_section_box: array)
        {
            QJsonObject one_section = one_section_box.toObject();
            __models.emplace_back(StationModel(one_section));
        }
    }
    else
    {
        qDebug() <<"Нет поля station";
        return;
    }
}

StationManager& StationManager::getInstance(const QJsonObject& json)
{
    static StationManager instance(json);
    return instance;
}

void StationManager::constructFromJson(const QJsonObject& json)
{
    if (json.contains("station"))
    {
        QJsonArray array = json["station"].toArray();

        for( const QJsonValue& one_section_box: array)
        {
            QJsonObject one_section = one_section_box.toObject();
            __models.emplace_back(StationModel(one_section));
        }
    }
    else
    {
        qDebug() <<"Нет поля station";
        return;
    }
}
QJsonObject StationManager::DumpToJson()
{
    QJsonObject sections_json;
    QJsonArray array;
    QJsonObject one_section;
    for(auto& model : __models)
    {
        one_section = model.DumpToJson();
        array.append(one_section);
    }
    sections_json["station"] = array;
    return sections_json;
}
void StationManager::addModel(const QString& name, const bool& calculate_crc)
{

}
void StationManager::changeModel(const size_t& id, const QString& name, const bool& calculate_crc)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].ChangeName(name);
    __models[id].changeFlag(calculate_crc);
    emit modelChanged(id);
}
void StationManager::changeModel(const QString& name, const bool& calculate_crc)
{
    for(auto& model : __models)
    {
        if(model.getName() == name)
        {
            model.changeFlag(calculate_crc);
            emit modelChanged(model.getId());
            return;
        }
    }
}
void StationManager::deleteModel(const QString& name)
{
    for (auto it = __models.begin(); it != __models.end(); ++it)
    {
        if (it->getName() == name) {
            size_t id = it->getId();
            it = __models.erase(it);
            emit modelDeleted(__models.size());
            return;
        }
    }
}
void StationManager::deleteModel(const size_t& pos)
{
    for (auto it = __models.begin(); it != __models.end(); ++it)
    {
        if (it->getId() == pos) {
            it = __models.erase(it);
            emit modelDeleted(pos);
            return;
        }
    }
}

void StationManager::changeCrc(const size_t& id,const size_t& pos_crc,  const size_t& size_crc,
               const size_t& start_crc,  const size_t& end_crc,  const QString& code)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].ChangeCrc(pos_crc, size_crc, start_crc, end_crc, code);
    emit modelChanged(id);
}
void StationManager::changeVirtualPort(const size_t& id, const QString& physical_interface, const int32_t& bod,
                       const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                       const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].ChangeVirtualPort(physical_interface, bod, bit_of_data, parity, stop_bits, flow_control);
}
void StationManager::changePackageTemplate(const size_t& id, const size_t& pac_id, const size_t& size, const QString& description, const QString& name)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].ChangePackageTemplate(pac_id, size, description,name);
}

void StationManager::changePackageTemplateSection(const size_t& id, const size_t& pac_temp_id, const size_t& sect_id, const size_t& package_zone_id,
                                  const size_t& start_pos, const size_t& size_sect)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].ChangeSection(pac_temp_id,sect_id, package_zone_id, start_pos, size_sect);
}
void StationManager::addPackageTemplateSection(const size_t& id, const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                               const size_t& start_pos, const size_t& size_sect)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].addSection(pac_id, sect_id, package_zone_id, start_pos, size_sect);
}
void StationManager::deletePackageTemplateSection(const size_t& id,const size_t& pac_id, const size_t& sect_id)
{
    if(id > __models.size())
    {
        throw std::invalid_argument("Incorrect id");
    }
    __models[id].deleteSection(pac_id, sect_id);
}

