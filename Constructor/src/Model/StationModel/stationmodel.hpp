#ifndef STATIONMODEL_HPP
#define STATIONMODEL_HPP

#include "../CRCModel/crcmodel.hpp"
#include "../VirtualPortModel/virtualportmodel.hpp"
#include"../../Controller/PackageTemplateManager/packagetemplatemanager.hpp"


class StationModel
{
public:
    StationModel(const QJsonObject& json);
    /*StationModel(QString name, bool calculate_crc, QString physical_interface, QSerialPort::DataBits __bit_of_data,
                 QSerialPort::Parity __parity, QSerialPort::StopBits __stop_bits,QSerialPort::FlowControl __flow_control,
                    size_t pt_size, QString pt_description, QString pt_name, size_t pac_zone_id, size_t start_pos, size_t size_sect,
                 size_t pos_crc, size_t size_crc, size_t start_calculate_crc, size_t end_calculate_crc, QString code);*/
    void ChangeCrc(const size_t& pos_crc,  const size_t& size_crc,
                   const size_t& start_crc,  const size_t& end_crc,  const QString& code);
    void ChangeVirtualPort(const QString& physical_interface, const int32_t& bod,
                           const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                           const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control);
    void ConstructFromJson(const QJsonObject& json);
    void ChangePackageTemplate(size_t& id, size_t size = 0, QString description = "", QString name = "",
                               size_t pos = -1, size_t pac_zone_id = -1, size_t start_pos = -1, size_t size_sect = -1 );

    QJsonObject DumpToJson();
    void ChangeName(const QString& new_name);

private:
    static size_t __id;
    QString __name;
    bool __calculate_crc;
    VirtualPortModel __virtual_port;
    PackageTemplateManager __package_template;
    CRCModel __crc;
};

#endif // STATIONMODEL_HPP
