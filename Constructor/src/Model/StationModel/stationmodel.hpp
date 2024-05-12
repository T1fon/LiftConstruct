#ifndef STATIONMODEL_HPP
#define STATIONMODEL_HPP

#include "../CRCModel/crcmodel.hpp"
#include "../VirtualPortModel/virtualportmodel.hpp"
#include"../../Controller/PackageTemplateManager/packagetemplatemanager.hpp"


class StationModel
{
public:
    StationModel(const QJsonObject& json);
    StationModel(const QString& name, const bool& calculate_crc);
    void ChangeCrc(const size_t& pos_crc,  const size_t& size_crc,
                   const size_t& start_crc,  const size_t& end_crc,  const QString& code);
    void ChangeVirtualPort(const QString& physical_interface, const int32_t& bod,
                           const QSerialPort::DataBits& bit_of_data, const QSerialPort::Parity& parity,
                           const QSerialPort::StopBits& stop_bits, const QSerialPort::FlowControl& flow_control);
    void ConstructFromJson(const QJsonObject& json);
    void ChangePackageTemplate(const size_t& id, const size_t& size, const QString& description, const QString& name);

    void ChangeSection(const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                       const size_t& start_pos, const size_t& size_sect);
    void addSection(const size_t& pac_id, const size_t& sect_id, const size_t& package_zone_id,
                    const size_t& start_pos, const size_t& size_sect);
    void deleteSection(const size_t& pac_id, const size_t& sect_id);

    QJsonObject DumpToJson();
    void ChangeName(const QString& new_name);
    void changeFlag(const bool& calculate_crc);
    PackageTemplateModel& getModel(const size_t& id);

    QString getName();
    size_t getId();

private:
    size_t __id;
    QString __name;
    bool __calculate_crc;
    VirtualPortModel __virtual_port;
    PackageTemplateManager __package_template;
    CRCModel __crc;
    static size_t __last_id;
};

#endif // STATIONMODEL_HPP
