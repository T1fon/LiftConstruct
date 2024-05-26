#include "stationmodel.hpp"

size_t StationModel::__last_id = 0;

StationModel::StationModel(const QJsonObject& json)
{
    if(json.empty())
    {
        __last_id = 0;
        __id = 0;
        __name.clear();
        __calculate_crc = false;
        __crc = std::make_unique<CRCModel>();
        __virtual_port = std::make_unique<VirtualPortModel>();
        __package_template = std::make_unique<PackageTemplateManager>(QJsonObject());
    }
    else
    {
        if(json.contains("id"))
        {
            __id = json["id"].toInteger(__last_id);
            if(__last_id < __id){__last_id = __id;};
        }

        if(json.contains("name"))
        {
            __name = json["name"].toString();
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля name)";
            return;
        }

        if(json.contains("calculate_crc"))
        {
            __calculate_crc = json["calculate_crc"].toBool();
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля calculate_crc)";
            return;
        }

        if(json.contains("crc"))
        {
            __crc = std::make_unique<CRCModel>(json["crc"].toObject());
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля crc)";
            return;
        }

        if(json.contains("virtual_port"))
        {
            __virtual_port = std::make_unique<VirtualPortModel>(json["virtual_port"].toObject());
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля virtual_port)";
            return;
        }

        if(json.contains("package_template"))
        {
            QJsonArray buf = json["package_template"].toArray();
            QJsonObject send;
            send["package_template"] = buf;
            __package_template = std::make_unique<PackageTemplateManager>(send);
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля package_template)";
            return;
        }
    }
}

StationModel::~StationModel(){}

StationModel::StationModel(const QString& name, const bool& calculate_crc) : __crc(), __package_template(), __virtual_port()
{
    __id = __last_id;
    __last_id++;
    __name = name;
    __calculate_crc = calculate_crc;
}

void StationModel::changeCrc( const size_t& pos_crc,  const size_t& size_crc,
                              const size_t& start_crc,  const size_t& end_crc,  const QString& code)
{
    __crc->setPositionCrc(pos_crc);
    __crc->setSizeCrc(size_crc);
    __crc->setStartCalculateCrc(start_crc);
    __crc->setEndCalculateCrc(end_crc);
    __crc->setCode(code);
}
void StationModel::changeVirtualPort(const QString& physical_interface, const int32_t& bod,
                                     const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                                     const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control)
{
    __virtual_port->setPhysicalInterface(physical_interface);
    __virtual_port->setBod(bod);
    __virtual_port->setBitOfData(bit_of_data);
    __virtual_port->setParity(parity);
    __virtual_port->setStopBits(stop_bits);
    __virtual_port->setFlowControl(flow_control);
}

void StationModel::changePackageTemplate(const size_t& id, const size_t& size, const QString& description, const QString& name)
{
    __package_template->changeElement(id,name,size,description);
}

void StationModel::constructFromJson(const QJsonObject& json)
{
    if(json.empty())
    {
        __last_id = 0;
        __id = 0;
        __name.clear();
        __calculate_crc = false;
        __crc = std::make_unique<CRCModel>();
        __virtual_port = std::make_unique<VirtualPortModel>();
        __package_template = std::make_unique<PackageTemplateManager>(QJsonObject());
    }
    else
    {
        if(json.contains("id"))
        {
            __id = json["id"].toInteger(__last_id);
            if(__last_id < __id){__last_id = __id;};
        }

        if(json.contains("name"))
        {
            __name = json["name"].toString();
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля name)";
            return;
        }

        if(json.contains("calculate_crc"))
        {
            __calculate_crc = json["calculate_crc"].toBool();
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля calculate_crc)";
            return;
        }

        if(json.contains("crc"))
        {
            __crc = std::make_unique<CRCModel>(json["crc"].toObject());
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля crc)";
            return;
        }

        if(json.contains("virtual_port"))
        {
            __virtual_port = std::make_unique<VirtualPortModel>(json["virtual_port"].toObject());
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля virtual_port)";
            return;
        }

        if(json.contains("package_template"))
        {
            QJsonArray buf = json["package_template"].toArray();
            QJsonObject send;
            send["package_template"] = buf;
            __package_template = std::make_unique<PackageTemplateManager>(send);
        }
        else
        {
            qDebug() << "Ошибка чтения json (нет такого поля package_template)";
            return;
        }
    }
}

QJsonObject StationModel::dumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<qint64>(__id);
    json["name"] = __name;
    json["calculate_crc"] = __calculate_crc;

    //virtual port
    json["virtual_port"] = __virtual_port->toJson();

    //package tempalte
    json["package_template"] = __package_template->DumpToJson();

    //crc
    json["crc"] = __crc->toJson();

    return json;
}

void StationModel::changeName(const QString& new_name)
{
    __name = new_name;
}

void StationModel::changeSection(const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                                 const size_t& start_pos, const size_t& size_sect)
{
    __package_template->changeElement(pac_id, sect_id, package_zone_id, start_pos, size_sect);
}
void StationModel::addSection(const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                              const size_t& start_pos, const size_t& size_sect)
{
    PackageTemplateModel& model = __package_template->getModel(pac_id);
    model.addSection(sect_id, package_zone_id, start_pos, size_sect);
}

void StationModel::deleteSection(const size_t& pac_id, const size_t& sect_id)
{
    PackageTemplateModel& model = __package_template->getModel(pac_id);
    model.deleteSection(sect_id);
}

PackageTemplateModel& StationModel::getModel(const size_t& id)
{
    return __package_template->getModel(id);
}

void StationModel::changeFlag(const bool& calculate_crc)
{
    __calculate_crc = calculate_crc;
}

QString StationModel::getName()
{
    return __name;
}
size_t StationModel::getId()
{
    return __id;
}
bool StationModel::getFlag()
{
    return __calculate_crc;
}

CRCModel& StationModel::getCRC()
{
    return *__crc;
}
VirtualPortModel& StationModel::getVirtualPort()
{
    return *__virtual_port;
}
