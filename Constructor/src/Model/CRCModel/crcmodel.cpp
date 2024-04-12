#include "crcmodel.hpp"

CRCModel::CRCModel(int position_crc, int size_crc, int start_calculate_crc, int end_calculate_crc, QString code)
{
    __position_crc = position_crc;
    __size_crc = size_crc;
    __start_calculate_crc = start_calculate_crc;
    __end_calculate_crc = end_calculate_crc;
    __code = code;
}

CRCModel::CRCModel(const CRCModel& other)
{
    __position_crc = other.__position_crc;
    __size_crc = other.__size_crc;
    __start_calculate_crc = other.__start_calculate_crc;
    __end_calculate_crc = other.__end_calculate_crc;
    __code = other.__code;
}

CRCModel::CRCModel(const QJsonObject& json)
{
    if (json.contains("position_crc"))
    {
        __position_crc = json["position_crc"].toInt();
    }
    else
    {
        __ErrorMsg("position_crc");
        return;
    }
    if (json.contains("size_crc"))
    {
        __size_crc = json["size_crc"].toInt();
    }
    else
    {
        __ErrorMsg("size_crc");
        return;
    }
    if (json.contains("start_calculate_crc"))
    {
        __start_calculate_crc = json["start_calculate_crc"].toInt();
    }
    else
    {
        __ErrorMsg("start_calculate_crc");
        return;
    }
    if (json.contains("end_calculate_crc"))
    {
        __end_calculate_crc = json["end_calculate_crc"].toInt();
    }
    else
    {
        __ErrorMsg("end_calculate_crc");
        return;
    }
    if (json.contains("code"))
    {
        __code = json["code"].toString();
    }
    else
    {
        __ErrorMsg("code");
        return;
    }
}
void CRCModel::__ErrorMsg(QString object)
{
    qDebug() << "Ошибка, json не считал строчку " <<object;
}


void CRCModel::SetPositionCrc(int position_crc)
{
    __position_crc = position_crc;
}

int CRCModel::GetPositionCrc()
{
    return __position_crc;
}

void CRCModel::SetSizeCrc(int size_crc)
{
    __size_crc = size_crc;
}

int CRCModel::GetSizeCrc()
{
    return __size_crc;
}

void CRCModel::SetStartCalculateCrc(int start_calculate_crc)
{
    __start_calculate_crc = start_calculate_crc;
}

int CRCModel::GetStartCalculateCrc()
{
    return __start_calculate_crc;
}

void CRCModel::SetEndCalculateCrc(int end_calculate_crc)
{
    __end_calculate_crc = end_calculate_crc;
}

int CRCModel::GetEndCalculateCrc()
{
    return __end_calculate_crc;
}

void CRCModel::SetCode(QString code)
{
    __code = code;
}

QString CRCModel::GetCode()
{
    return __code;
}
QJsonObject CRCModel::toJson()
{
    QJsonObject json;
    json["position_crc"] = __position_crc;
    json["size_crc"] = __size_crc;
    json["start_calculate_crc"] = __start_calculate_crc;
    json["end_calculate_crc"] = __end_calculate_crc;
    json["code"] = __code;
    return json;
}

void CRCModel::ConstructFromJson(const QJsonObject& json)
{
    if (json.contains("position_crc"))
    {
        __position_crc = json["position_crc"].toInt();
    }
    else
    {
        __ErrorMsg("position_crc");
        return;
    }
    if (json.contains("size_crc"))
    {
        __size_crc = json["size_crc"].toInt();
    }
    else
    {
        __ErrorMsg("size_crc");
        return;
    }
    if (json.contains("start_calculate_crc"))
    {
        __start_calculate_crc = json["start_calculate_crc"].toInt();
    }
    else
    {
        __ErrorMsg("start_calculate_crc");
        return;
    }
    if (json.contains("end_calculate_crc"))
    {
        __end_calculate_crc = json["end_calculate_crc"].toInt();
    }
    else
    {
        __ErrorMsg("end_calculate_crc");
        return;
    }
    if (json.contains("code"))
    {
        __code = json["code"].toString();
    }
    else
    {
        __ErrorMsg("code");
        return;
    }
}
