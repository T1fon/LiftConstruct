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
    CRCModel();
    void setPositionCrc(const size_t& position_crc);
    void setSizeCrc(const size_t& size_crc);
    void setStartCalculateCrc(const size_t& start_calculate_crc);
    void setEndCalculateCrc(const size_t& end_calculate_crc);
    void setCode(const QString& code);
    size_t& getPositionCrc();
    size_t& getSizeCrc();
    size_t& getStartCalculateCrc();
    size_t& getEndCalculateCrc();
    QString& getCode();
    QJsonObject toJson();
    void constructFromJson(const QJsonObject& json);
private:

    size_t __position_crc;
    size_t __size_crc;
    size_t __start_calculate_crc;
    size_t __end_calculate_crc;
    QString __code;
    void __ErrorMsg(QString object);
};

#endif // CRCMODEL_HPP
