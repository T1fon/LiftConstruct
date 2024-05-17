#include "packagemodel.hpp"
int PackageModel::__last_id = 0;

PackageModel::PackageModel(const QJsonObject& json)
{
    if(json.contains("id"))
    {
        __id = json["id"].toInteger(__last_id);
        if(__last_id < __id){__last_id = __id;}
    }
    else
    {
        qDebug() << "остутствует поле id";
        return;
    }
    if(json.contains("station_id"))
    {
        __station_id = json["station_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля station_id";
        __last_id--;
        return;
    }
    if(json.contains("package_template_id"))
    {
        __package_template_id = json["package_template_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля package_template_id";
        __last_id--;
        return;
    }
    if(json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "json не содержит поля name";
        __last_id--;
        return;
    }
    if (json.contains("data"))
    {
        QString data_str = json["data"].toString();
        QVector<uint8_t> data_vector;
        for (const QChar &ch : data_str)
        {
            if (ch == QLatin1Char('0'))
                data_vector.append(0);
            else if (ch == QLatin1Char('1'))
                data_vector.append(1);
            else {
                qDebug() << "Неверный символ в поле данных";
                return;
            }
        }
        __data = data_vector;
    }
    else
    {
        qDebug() << "json не содержит поля data";
        __last_id--;
        return;
    }
    if(json.contains("description"))
    {
        __description = json["description"].toString();
    }
    else
    {
        qDebug() << "json не содержит поля description";
        __last_id--;
        return;
    }

}
PackageModel::PackageModel(const size_t& station_id, const size_t& p_t_id, const QString& name,
                           const QVector<uint8_t>& data, const QString& description)
{
    __id = __last_id;
    __last_id++;
    __station_id = station_id;
    __package_template_id = p_t_id;
    __name = name;
    __data = data;
    __description = description;
}
void PackageModel::SetStationId(const size_t& station_id)
{
    __station_id = station_id;
}
void PackageModel::SetPackageTamplateId(const size_t& package_tamplate_id)
{
    __package_template_id = package_tamplate_id;
}
void PackageModel::SetName(const QString& name)
{
    __name = name;
}
void PackageModel::SetData(const QVector<uint8_t>& data)
{
    __data = data;
}
void PackageModel::SetDescription(const QString& description)
{
    __description = description;
}
size_t PackageModel::GetId()
{
    return __id;
}
size_t PackageModel::GetStationId()
{
    return __station_id;
}
size_t PackageModel::GetPackageTemplateId()
{
    return __package_template_id;
}
QString PackageModel::GetName()
{
    return __name;
}
QVector<uint8_t> PackageModel::GetData()
{
    return __data;
}
QString PackageModel::GetDescription()
{
    return __description;
}
void PackageModel::SetByte(const size_t& index, const uint8_t& value)
{
    if (index >= 0 && index < __data.size())
    {
        __data[index] = value;
    }
    else
    {
        qDebug() << "Неверный индекс для установки байта";
    }
}
void PackageModel::ConstructFromJson(const QJsonObject& json)
{
    /*__id = __last_id;
    __last_id++;*/
   /* if(json.contains("id"))
    {
        __id = json["id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля id";
        return;
    }*/
    if(json.contains("station_id"))
    {
        __station_id = json["station_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля station_id";
       // __last_id--;
        return;
    }
    if(json.contains("package_template_id"))
    {
        __package_template_id = json["package_template_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля package_template_id";
        //__last_id--;
        return;
    }
    if(json.contains("name"))
    {
        __name = json["name"].toString();
    }
    else
    {
        qDebug() << "json не содержит поля name";
       // __last_id--;
        return;
    }
    if(json.contains("data"))
    {
        QString buffer = json["data"].toString();
        QByteArray data_bytes = buffer.toUtf8();
        QVector<uint8_t> data_vector;
        for (char byte : data_bytes)
        {
            data_vector.append(static_cast<uint8_t>(byte));
        }
        __data = data_vector;
    }
    else
    {
        qDebug() << "json не содержит поля data";
        //__last_id--;
        return;
    }
    if(json.contains("description"))
    {
        __name = json["description"].toString();
    }
    else
    {
        qDebug() << "json не содержит поля description";
        //__last_id--;
        return;
    }
}
QJsonObject PackageModel::DumpToJson()
{
    QJsonObject json;
    json["id"] = static_cast<int>(__id);
    json["station_id"] = static_cast<int>(__station_id);
    json["package_template_id"] = static_cast<int>(__package_template_id);
    json["name"] = __name;
    QString data_string;
    for(uint8_t byte : __data)
    {
        if (byte == 0)
            data_string.append('0');
        else if (byte == 1)
            data_string.append('1');
        else
        {
            qDebug() << "Неверное значение байта в векторе данных";
            break;
        }
    }
    json["data"] = data_string;
    json["description"] = __description;
    return json;
}
