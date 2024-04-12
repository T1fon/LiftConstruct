#ifndef CRCMODEL_HPP
#define CRCMODEL_HPP

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

class CRCModel
{
public:
    CRCModel(int position_crc, int size_crc, int start_calculate_crc, int end_calculate_crc, QString code);
    CRCModel(const CRCModel& other);
    CRCModel(const QJsonObject& json);
    void SetPositionCrc(int position_crc);
    void SetSizeCrc(int size_crc);
    void SetStartCalculateCrc(int start_calculate_crc);
    void SetEndCalculateCrc(int end_calculate_crc);
    void SetCode(QString code);
    int GetPositionCrc();
    int GetSizeCrc();
    int GetStartCalculateCrc();
    int GetEndCalculateCrc();
    QString GetCode();
    QJsonObject toJson();
    void ConstructFromJson(const QJsonObject& json);
private:

    int __position_crc;
    int __size_crc;
    int __start_calculate_crc;
    int __end_calculate_crc;
    QString __code;
    void __ErrorMsg(QString object);
};

#endif // CRCMODEL_HPP
