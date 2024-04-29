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

void StationModel::ChangeCrc(const QJsonObject& json)
{
    if(json.contains("calculate_crc"))
    {
        __calculate_crc = json["caclulate_crc"].toBool();
    }

    if(json.contains("position_crc"))
    {
        __crc.SetPositionCrc(json["position_crc"].toInt());
    }

    if(json.contains("size_crc"))
    {
        __crc.SetSizeCrc(json["size_crc"].toInt());
    }

    if(json.contains("start_calculate_crc"))
    {
        __crc.SetStartCalculateCrc(json["start_calculate_crc"].toInt());
    }

    if(json.contains("end_calculate_crc"))
    {
        __crc.SetEndCalculateCrc(json["end_calculate_crc"].toInt());
    }

    if(json.contains("end_calculate_crc"))
    {
        __crc.SetEndCalculateCrc(json["end_calculate_crc"].toInt());
    }
    if(json.contains("code"))
    {
        __crc.SetCode(json["code"].toString());
    }
}
void StationModel::ChangeVirtualPort(const QJsonObject& json)
{
    if(json.contains("physical_interface"))
    {
        __virtual_port.SetPhysicalInterface(json["physical_interface"].toString());
    }

    if(json.contains("bod"))
    {
        __virtual_port.SetBod(json["bod"].toInt());
    }

    if(json.contains("bit_of_data"))
    {
        QSerialPort::DataBits bit_of_data = static_cast<QSerialPort::DataBits>(json["bit_of_data"].toInt());
        __virtual_port.SetBitOfData(bit_of_data);
    }

    if(json.contains("parity"))
    {
        QSerialPort::Parity parity = static_cast<QSerialPort::Parity>(json["parity"].toInt());
        __virtual_port.SetParity(parity);
    }

    if(json.contains("stop_bits"))
    {
        QSerialPort::StopBits stop_bits = static_cast<QSerialPort::StopBits>(json["stop_bits"].toInt());
        __virtual_port.SetStopBits(stop_bits);
    }

    if(json.contains("flow_control"))
    {
        QSerialPort::FlowControl flow_control = static_cast<QSerialPort::FlowControl>(json["flow_control"].toInt());
        __virtual_port.SetFlowControl(flow_control);
    }
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

