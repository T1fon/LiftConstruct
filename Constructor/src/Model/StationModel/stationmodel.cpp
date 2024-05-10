#include "stationmodel.hpp"

size_t StationModel::__id = 0;

StationModel::StationModel(const QJsonObject& json) : __crc(json), __package_template(json), __virtual_port(json)
{
    __id++;
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
        __calculate_crc = json["caclulate_crc"].toBool();
    }
    else
    {
        qDebug() << "Ошибка чтения json (нет такого поля calculate_crc)";
        return;
    }
}

void StationModel::ChangeCrc( const size_t& pos_crc,  const size_t& size_crc,
                              const size_t& start_crc,  const size_t& end_crc,  const QString& code)
{
    __crc.SetPositionCrc(pos_crc);
    __crc.SetSizeCrc(size_crc);
    __crc.SetStartCalculateCrc(start_crc);
    __crc.SetEndCalculateCrc(end_crc);
    __crc.SetCode(code);
}
void StationModel::ChangeVirtualPort(const QString& physical_interface, const int32_t& bod,
                                     const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                                     const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control)
{
    __virtual_port.SetPhysicalInterface(physical_interface);
    __virtual_port.SetBod(bod);
    __virtual_port.SetBitOfData(bit_of_data);
    __virtual_port.SetParity(parity);
    __virtual_port.SetStopBits(stop_bits);
    __virtual_port.SetFlowControl(flow_control);
}

void StationModel::ChangePackageTemplate(size_t& id, size_t size, QString description, QString name,
                                         size_t pos, size_t pac_zone_id, size_t start_pos, size_t size_sect)
{
    __package_template.ChangeElement(id,name,size,description,pos,pac_zone_id,start_pos,size_sect);
}

void StationModel::ConstructFromJson(const QJsonObject& json)
{
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
        __calculate_crc = json["caclulate_crc"].toBool();
    }
    else
    {
        qDebug() << "Ошибка чтения json (нет такого поля calculate_crc)";
        return;
    }
    if(json.contains("crc"))
    {
        QJsonObject crc_json;
        crc_json["position_crc"] = json["position_crc"];
        crc_json["size_crc"] = json["size_crc"];
        crc_json["start_calculate_crc"] = json["start_calculate_crc"];
        crc_json["end_calculate_crc"] = json["end_calculate_crc"];
        crc_json["code"] = json["code"];
        __crc.ConstructFromJson(crc_json);
    }
    else
    {
        qDebug() << "Ошибка чтения json (Отсутствует поле CRC)";
        return;
    }
    if(json.contains("virtual_port"))
    {
        QJsonObject vp_json;
        vp_json["physical_interface"] = json["physical_interface"];
        vp_json["bod"] = json["bod"];
        vp_json["bit_of_data"] = json["bit_of_data"];
        vp_json["parity"] = json["parity"];
        vp_json["stop_bits"] = json["stop_bits"];
        vp_json["flow_control"] = json["flow_control"];
        __virtual_port.ConstructFromJson(vp_json);
    }
    else
    {
        qDebug() << "Ошибка чтения json (Отсутствует поле Virtual Port)";
        return;
    }
    if(json.contains("package_tempalte"))
    {
        QJsonObject pt_object;
        pt_object["package_tempalte"] = json["package_tempalte"];
        __package_template.ConstructFromJson(pt_object);
    }
    else
    {
        qDebug() << "Ошибка чтения json (Отсутствует поле Package Tempalte)";
        return;
    }
}

QJsonObject StationModel::DumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<qint64>(__id);
    json["name"] = __name;
    json["calculate_crc"] = __calculate_crc;

    //virtual port
    json["virtual_port"] = __virtual_port.toJson();

    //package tempalte
    json["package_tempalte"] = __package_template.DumpToJson();

    //crc
    json["crc"] = __crc.toJson();

    return json;
}

void StationModel::ChangeName(const QString& new_name)
{
    __name = new_name;
}

