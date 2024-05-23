#include "crcmodel.hpp"

CRCModel::CRCModel(const size_t& position_crc, const size_t& size_crc,
                   const size_t& start_calculate_crc, const size_t& end_calculate_crc,  const QString& code)
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
CRCModel::CRCModel()
{
    __position_crc = 0;
    __size_crc = 0;
    __start_calculate_crc = 0;
    __end_calculate_crc = 0;
    __code = 0;
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


void CRCModel::setPositionCrc(const size_t& position_crc)
{
    __position_crc = position_crc;
}

size_t& CRCModel::getPositionCrc()
{
    return __position_crc;
}

void CRCModel::setSizeCrc(const size_t& size_crc)
{
    __size_crc = size_crc;
}

size_t& CRCModel::getSizeCrc()
{
    return __size_crc;
}

void CRCModel::setStartCalculateCrc(const size_t& start_calculate_crc)
{
    __start_calculate_crc = start_calculate_crc;
}

size_t& CRCModel::getStartCalculateCrc()
{
    return __start_calculate_crc;
}

void CRCModel::setEndCalculateCrc(const size_t& end_calculate_crc)
{
    __end_calculate_crc = end_calculate_crc;
}

size_t& CRCModel::getEndCalculateCrc()
{
    return __end_calculate_crc;
}

void CRCModel::setCode(const QString& code)
{
    __code = code;
}

QString& CRCModel::getCode()
{
    return __code;
}
QJsonObject CRCModel::toJson()
{
    QJsonObject json;
    json["position_crc"] = static_cast<int>(__position_crc);
    json["size_crc"] = static_cast<int>(__size_crc);
    json["start_calculate_crc"] = static_cast<int>(__start_calculate_crc);
    json["end_calculate_crc"] = static_cast<int>(__end_calculate_crc);
    json["code"] = __code;
    return json;
}

void CRCModel::constructFromJson(const QJsonObject& json)
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
