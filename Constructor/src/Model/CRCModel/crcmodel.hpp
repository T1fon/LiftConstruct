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
    CRCModel(const size_t& position_crc, const size_t& size_crc,
             const size_t& start_calculate_crc, const size_t& end_calculate_crc,  const QString& code);
    CRCModel(const CRCModel& other);
    CRCModel(const QJsonObject& json);
    void SetPositionCrc(const size_t& position_crc);
    void SetSizeCrc(const size_t& size_crc);
    void SetStartCalculateCrc(const size_t& start_calculate_crc);
    void SetEndCalculateCrc(const size_t& end_calculate_crc);
    void SetCode(const QString& code);
    size_t& GetPositionCrc();
    size_t& GetSizeCrc();
    size_t& GetStartCalculateCrc();
    size_t& GetEndCalculateCrc();
    QString&GetCode();
    QJsonObject toJson();
    void ConstructFromJson(const QJsonObject& json);
private:

    size_t __position_crc;
    size_t __size_crc;
    size_t __start_calculate_crc;
    size_t __end_calculate_crc;
    QString __code;
    void __ErrorMsg(QString object);
};

#endif // CRCMODEL_HPP
