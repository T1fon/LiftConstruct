#include "virtualportmodel.hpp"

VirtualPortModel::VirtualPortModel(const QString& physical_interface, const int32_t& bod, const QSerialPort::DataBits& bit_of_data,
                                   const QSerialPort::Parity& parity, const QSerialPort::StopBits& stop_bits,
                                   const QSerialPort::FlowControl& flow_control)
{
    __physical_interface = physical_interface;
    __bod = bod;
    __bit_of_data = bit_of_data;
    __parity = parity;
    __stop_bits = stop_bits;
    __flow_control = flow_control;
}
VirtualPortModel::VirtualPortModel()
{
    __physical_interface = "";
    __bod = 0;
    __bit_of_data = QSerialPort::Data8;
    __parity = QSerialPort::NoParity;
    __stop_bits = QSerialPort::OneStop;
    __flow_control = QSerialPort::NoFlowControl;
}

VirtualPortModel::VirtualPortModel(const VirtualPortModel& other)
{
    __physical_interface = other.__physical_interface;
    __bod = other.__bod;
    __bit_of_data = other.__bit_of_data;
    __parity = other.__parity;
    __stop_bits = other.__stop_bits;
    __flow_control = other.__flow_control;
}
VirtualPortModel::VirtualPortModel(const QJsonObject& json)
{
    if (json.contains("physical_interface"))
    {
        __physical_interface = json["physical_interface"].toString();
    }
    else
    {
        __ErrorMsg("physical_interface");
        return;
    }

    if (json.contains("bod"))
    {
        __bod = json["bod"].toInt();
    }
    else
    {
        __ErrorMsg("bod");
        return;
    }

    if (json.contains("bit_of_data"))
    {
        __bit_of_data = static_cast<QSerialPort::DataBits>(json["bit_of_data"].toInt());
    }
    else
    {
        __ErrorMsg("bit_of_data");
        return;
    }

    if (json.contains("parity"))
    {
        __parity = static_cast<QSerialPort::Parity>(json["parity"].toInt());
    }
    else
    {
        __ErrorMsg("parity");
        return;
    }

    if (json.contains("stop_bits"))
    {
        __stop_bits = static_cast<QSerialPort::StopBits>(json["stop_bits"].toInt());
    }
    else
    {
        __ErrorMsg("stop_bits");
        return;
    }

    if (json.contains("flow_control"))
    {
        __flow_control = static_cast<QSerialPort::FlowControl>(json["flow_control"].toInt());
    }
    else
    {
        __ErrorMsg("flow_control");
        return;
    }
}

void VirtualPortModel::__ErrorMsg(QString object)
{
    qDebug() << "Ошибка, json не считал строчку " <<object;
}

void VirtualPortModel::SetPhysicalInterface(const QString& physical_interface)
{
    __physical_interface = physical_interface;
}

QString VirtualPortModel::GetPhysicalInterface() const
{
    return __physical_interface;
}

void VirtualPortModel::SetBod(const int32_t& bod)
{
    __bod = bod;
}

int32_t VirtualPortModel::GetBod() const
{
    return __bod;
}

void VirtualPortModel::SetBitOfData(const QSerialPort::DataBits& bit_of_data)
{
    __bit_of_data = bit_of_data;
}

QSerialPort::DataBits VirtualPortModel::GetBitOfData() const
{
    return __bit_of_data;
}

void VirtualPortModel::SetParity(const QSerialPort::Parity& parity)
{
    __parity = parity;
}

QSerialPort::Parity VirtualPortModel::GetParity() const
{
    return __parity;
}

void VirtualPortModel::SetStopBits(const QSerialPort::StopBits& stop_bits)
{
    __stop_bits = stop_bits;
}

QSerialPort::StopBits VirtualPortModel::GetStopBits() const
{
    return __stop_bits;
}

void VirtualPortModel::SetFlowControl(const QSerialPort::FlowControl& flow_control)
{
    __flow_control = flow_control;
}

QSerialPort::FlowControl VirtualPortModel::GetFlowControl() const
{
    return __flow_control;
}

QJsonObject VirtualPortModel::toJson()
{
    QJsonObject json;
    json["physical_interface"] = __physical_interface;
    json["bod"] = __bod;
    json["bit_of_data"] = static_cast<int>(__bit_of_data);
    json["parity"] = static_cast<int>(__parity);
    json["stop_bits"] = static_cast<int>(__stop_bits);
    json["flow_control"] = static_cast<int>(__flow_control);

    return json;
}

void VirtualPortModel::ConstructFromJson(const QJsonObject& json)
{
    if (json.contains("physical_interface"))
    {
        __physical_interface = json["physical_interface"].toString();
    }
    else
    {
        __ErrorMsg("physical_interface");
        return;
    }

    if (json.contains("bod"))
    {
        __bod = json["bod"].toInt();
    }
    else
    {
        __ErrorMsg("bod");
        return;
    }

    if (json.contains("bit_of_data"))
    {
        __bit_of_data = static_cast<QSerialPort::DataBits>(json["bit_of_data"].toInt());
    }
    else
    {
        __ErrorMsg("bit_of_data");
        return;
    }

    if (json.contains("parity"))
    {
        __parity = static_cast<QSerialPort::Parity>(json["parity"].toInt());
    }
    else
    {
        __ErrorMsg("parity");
        return;
    }

    if (json.contains("stop_bits"))
    {
        __stop_bits = static_cast<QSerialPort::StopBits>(json["stop_bits"].toInt());
    }
    else
    {
        __ErrorMsg("stop_bits");
        return;
    }

    if (json.contains("flow_control"))
    {
        __flow_control = static_cast<QSerialPort::FlowControl>(json["flow_control"].toInt());
    }
    else
    {
        __ErrorMsg("flow_control");
        return;
    }
}
