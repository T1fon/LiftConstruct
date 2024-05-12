#ifndef STATIONMANAGER_HPP
#define STATIONMANAGER_HPP

#include <QJsonObject>
#include <QJsonArray>
#include "../../Model/StationModel/stationmodel.hpp"

class StationManager
{
public:
    //StationManager(const QJsonObject& json);
    static StationManager& getInstance(const QJsonObject& json);

    void constructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();

    void addModel(const QString& name, const bool& calculate_crc);
    void changeModel(const size_t& id, const QString& name, const bool& calculate_crc);
    void changeModel(const QString& name, const bool& calculate_crc);
    void deleteModel(const QString& name);
    void deleteModel(const size_t& pos);

    void changeCrc(const size_t& id, const size_t& pos_crc,  const size_t& size_crc,
                   const size_t& start_crc,  const size_t& end_crc,  const QString& code);
    void changeVirtualPort(const size_t& id, const QString& physical_interface, const int32_t& bod,
                           const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                           const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control);
    void changePackageTemplate(const size_t& id, const size_t& pac_id, const size_t& size, const QString& description, const QString& name);

    void changePackageTemplateSection(const size_t& id, const size_t& pac_temp_id, const size_t& sect_id, const size_t& package_zone_id,
                                      const size_t& start_pos, const size_t& size_sect);
    void addPackageTemplateSection(const size_t& id, const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                                   const size_t& start_pos, const size_t& size_sect);
    void deletePackageTemplateSection(const size_t& id,const size_t& pac_id, const size_t& sect_id);

private:
    QVector<StationModel> __models;
signals:
    void modelAdded(const size_t& size);
    void modelChanged(const size_t& pos);
    void modelDeleted(const size_t& size);

    StationManager(const QJsonObject& json);
};

#endif // STATIONMANAGER_HPP