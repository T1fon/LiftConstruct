#include "sequenceofpackagemodel.hpp"

SequenceOfPackageModel::SequenceOfPackageModel(const QJsonObject& json)
{
    if(json.contains("position"))
    {
        __position = json["position"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля position";
        return;
    }

    if(json.contains("package_id"))
    {
        __package_id = json["package_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля package_id";
        return;
    }

    if(json.contains("action"))
    {
        int act = json["action"].toInt();
        if(act == 0)
        {
            __action = SequenceOfPackageModel::SEND;
        }
        else if(act == 1)
        {
            __action = SequenceOfPackageModel::RECEIVE;
        }
        else
        {
            qDebug() << "Некорректный action";
            return;
        }
    }
    else
    {
        qDebug() << "json не содержит поля action";
        return;
    }
}

SequenceOfPackageModel::SequenceOfPackageModel(const SequenceOfPackageModel& other)
    : QObject(other.parent()), __position(other.__position), __package_id(other.__package_id), __action(other.__action)
{
}

void SequenceOfPackageModel::SetPosition(const size_t& position)
{
    __position = position;
}

void SequenceOfPackageModel::SetPackageId(const size_t& package_id)
{
    __package_id = package_id;
}
void SequenceOfPackageModel::SetAction(const size_t& act)
{
    if(act == 0)
    {
        __action = SequenceOfPackageModel::SEND;
    }
    else if(act == 1)
    {
        __action = SequenceOfPackageModel::RECEIVE;
    }
    else
    {
        qDebug() << "Некорректное значение action";
        return;
    }
}

size_t SequenceOfPackageModel::GetPosition() const
{
    return __position;
}

size_t SequenceOfPackageModel::GetPackageId() const
{
    return __package_id;
}

size_t SequenceOfPackageModel::GetAction() const
{
    if(__action == SequenceOfPackageModel::SEND)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void SequenceOfPackageModel::ConstructFromJson(const QJsonObject& json)
{
    if(json.contains("position"))
    {
        __position = json["position"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля position";
        return;
    }

    if(json.contains("package_id"))
    {
        __package_id = json["package_id"].toInt();
    }
    else
    {
        qDebug() << "json не содержит поля package_id";
        return;
    }

    if(json.contains("action"))
    {
        int act = json["action"].toInt();
        if(act == 0)
        {
            __action = SequenceOfPackageModel::SEND;
        }
        else if(act == 1)
        {
            __action = SequenceOfPackageModel::RECEIVE;
        }
        else
        {
            qDebug() << "Некорректный action";
            return;
        }
    }
    else
    {
        qDebug() << "json не содержит поля action";
        return;
    }
}

QJsonObject SequenceOfPackageModel::DumpToJson() const
{
    QJsonObject json;
    json["position"] = static_cast<int>(__position);
    json["package_id"] = static_cast<int>(__package_id);
    if(__action == SequenceOfPackageModel::SEND)
    {
        json["action"] = 0;
    }
    else
    {
        json["action"] = 1;
    }
    return json;
}

