#include "sequenceofpackagemodel.hpp"

SequenceOfPackageModel::SequenceOfPackageModel(const QJsonObject& json)
{
    if(json.empty())
    {
        __position = 0;
        __package_id = 0;
        __action = RECEIVE;
    }
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

SequenceOfPackageModel::SequenceOfPackageModel(const size_t& position, const size_t& package_id, const size_t& action)
{
    __position = position;
    __package_id = package_id;
    if(action == 0)
    {
        __action = SequenceOfPackageModel::SEND;
    }
    else if(action == 1)
    {
        __action = SequenceOfPackageModel::RECEIVE;
    }
    else
        return;
}

void SequenceOfPackageModel::setPosition(const size_t& position)
{
    __position = position;
}

void SequenceOfPackageModel::setPackageId(const size_t& package_id)
{
    __package_id = package_id;
}
void SequenceOfPackageModel::setAction(const size_t& act)
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

size_t SequenceOfPackageModel::getPosition() const
{
    return __position;
}

size_t SequenceOfPackageModel::getPackageId() const
{
    return __package_id;
}

size_t SequenceOfPackageModel::getAction() const
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
void SequenceOfPackageModel::constructFromJson(const QJsonObject& json)
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

QJsonObject SequenceOfPackageModel::dumpToJson() const
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

