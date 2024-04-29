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

