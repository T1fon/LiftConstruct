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

void SequenceOfPackageModel::SetPosition(int position)
{
    __position = position;
}

void SequenceOfPackageModel::SetPackageId(int package_id)
{
    __package_id = package_id;
}
void SequenceOfPackageModel::SetAction(int act)
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

int SequenceOfPackageModel::GetPosition() const
{
    return __position;
}

int SequenceOfPackageModel::GetPackageId() const
{
    return __package_id;
}

int SequenceOfPackageModel::GetAction()
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
    json["position"] = __position;
    json["package_id"] = __package_id;
    if(__action == SequenceOfPackageModel::SEND)
    {
        json["action"] = 1;
    }
    else
    {
        json["action"] = 0;
    }
    return json;
}

