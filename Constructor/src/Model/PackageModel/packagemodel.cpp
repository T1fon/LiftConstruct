#include "packagemodel.hpp"
int PackageModel::__last_id = 0;

PackageModel::PackageModel(const QJsonObject& json)
{
    __id = __last_id;
    __last_id++;
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
        __last_id--;
        return;
    }
    if(json.contains("description"))
    {
        __name = json["description"].toString();
    }
    else
    {
        qDebug() << "json не содержит поля description";
        __last_id--;
        return;
    }

}
PackageModel::PackageModel(int station_id, int p_t_id, QString name, QVector<uint8_t> data, QString description)
{
    __id = __last_id;
    __last_id++;
    __station_id = station_id;
    __package_template_id = p_t_id;
    __name = name;
    __data = data;
    __description = description;
}
void PackageModel::SetStationId(int station_id)
{
    __station_id = station_id;
}
void PackageModel::SetPackageTamplateId(int package_tamplate_id)
{
    __package_template_id = package_tamplate_id;
}
void PackageModel::SetName(QString name)
{
    __name = name;
}
void PackageModel::SetData(QVector<uint8_t> data)
{
    __data = data;
}
void PackageModel::SetDescription(QString description)
{
    __description = description;
}
int PackageModel::GetId()
{
    return __id;
}
int PackageModel::GetStationId()
{
    return __station_id;
}
int PackageModel::GetPackageTemplateId()
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
void PackageModel::SetByte(int index, uint8_t value)
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
    json["id"] = __id;
    json["station_id"] = __station_id;
    json["package_template_id"] = __package_template_id;
    json["name"] = __name;
    QString data_string;
    for(uint8_t byte : __data)
    {
        data_string.append(static_cast<char>(byte));
    }
    json["data"] = data_string;
    json["description"] = __description;
}
