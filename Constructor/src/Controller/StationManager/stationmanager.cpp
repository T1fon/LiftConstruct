#include "stationmanager.hpp"

StationManager::StationManager(const QJsonObject& json, QObject* parent)
    : QObject(parent) {
    if (json.contains("station")) {
        QJsonArray array = json["station"].toArray();

        for (const QJsonValue& one_section_box : array) {
            QJsonObject one_section = one_section_box.toObject();
            std::unique_ptr<StationModel> model = std::make_unique<StationModel>(one_section);
            __models.push_back(std::move(model));
        }
    } else {
        qDebug() << "Нет поля station";
    }
}

StationManager::~StationManager() {}

StationManager& StationManager::getInstance(const QJsonObject& json) {
    static StationManager instance(json);
    return instance;
}

void StationManager::constructFromJson(const QJsonObject& json)
{
    if (json.contains("station"))
    {
        __models.clear();
        QJsonArray array = json["station"].toArray();

        for (const QJsonValue& one_section_box : array)
        {
            QJsonObject one_section = one_section_box.toObject();
            std::unique_ptr<StationModel> modelPtr = std::make_unique<StationModel>(one_section);
            __models.push_back(std::move(modelPtr));
        }
    }
    else
    {
        qDebug() << "Нет поля station";
        return;
    }
}
QJsonArray StationManager::DumpToJson()
{
    QJsonArray array;
    for(auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        array.append((*it)->dumpToJson());
    }
    return array;
}
void StationManager::addModel(const QString& name, const bool& calculate_crc)
{

}
void StationManager::changeModel(const size_t& id, const QString& name, const bool& calculate_crc)
{
    for(auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if( (*it)->getId() == id)
        {
            (*it)->changeName(name);
            (*it)->changeFlag(calculate_crc);
            emit modelChanged(id);
        }
    }

}
void StationManager::changeModel(const QString& name, const bool& calculate_crc)
{
   for(auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getName() == name)
        {
            (*it)->changeFlag(calculate_crc);
            emit modelChanged((*it)->getId());
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}
void StationManager::deleteModel(const QString& name) {
    for (auto it = __models.begin(); it != __models.end(); ) {
        if ((*it)->getName() == name) {
            size_t id = (*it)->getId();
            it = __models.erase(it);  // erase возвращает следующий итератор
            emit modelDeleted(id);
            return;
        } else {
            ++it;  // Инкремент только если элемент не был удален
        }
    }
    throw std::invalid_argument("Incorrect name");
}
void StationManager::deleteModel(const size_t& pos)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if ((*it)->getId() == pos) {
            it = __models.erase(it);
            emit modelDeleted(pos);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}

void StationManager::changeCrc(const size_t& id,const size_t& pos_crc,  const size_t& size_crc,
               const size_t& start_crc,  const size_t& end_crc,  const QString& code)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->changeCrc(pos_crc, size_crc, start_crc, end_crc, code);
            emit modelChanged(id);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}
void StationManager::changeVirtualPort(const size_t& id, const QString& physical_interface, const int32_t& bod,
                       const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                       const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->changeVirtualPort(physical_interface, bod, bit_of_data, parity, stop_bits, flow_control);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}
void StationManager::changePackageTemplate(const size_t& id, const size_t& pac_id, const size_t& size, const QString& description, const QString& name)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->changePackageTemplate(pac_id, size, description,name);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}

void StationManager::changePackageTemplateSection(const size_t& id, const size_t& pac_temp_id, const size_t& sect_id, const size_t& package_zone_id,
                                  const size_t& start_pos, const size_t& size_sect)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->changeSection(pac_temp_id,sect_id, package_zone_id, start_pos, size_sect);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}
void StationManager::addPackageTemplateSection(const size_t& id, const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                               const size_t& start_pos, const size_t& size_sect)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->addSection(pac_id, sect_id, package_zone_id, start_pos, size_sect);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");

}
void StationManager::deletePackageTemplateSection(const size_t& id,const size_t& pac_id, const size_t& sect_id)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            (*it)->deleteSection(pac_id, sect_id);
            return;
        }
    }
    throw std::invalid_argument("Incorrect id");
}

StationModel& StationManager::getModel(const size_t& id)
{
    for (auto it = __models.cbegin(); it != __models.cend(); ++it)
    {
        if((*it)->getId() == id)
        {
            return *(*it);
        }
    }
    throw std::invalid_argument("Incorrect id");
}

size_t StationManager::getSize(){return __models.size();}

