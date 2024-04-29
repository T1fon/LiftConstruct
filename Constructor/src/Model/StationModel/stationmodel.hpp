#ifndef STATIONMODEL_HPP
#define STATIONMODEL_HPP

#include "../CRCModel/crcmodel.hpp"
#include "../VirtualPortModel/virtualportmodel.hpp"
#include"../../Controller/PackageTemplateManager/packagetemplatemanager.hpp"

class StationModel
{
public:
    StationModel(const QJsonObject& json);
    void ChangeCrc(const QJsonObject& json);
    void ChangeVirtualPort(const QJsonObject& json);
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson();
    void ChangeName(QString new_name);

private:
    static size_t __id;
    QString __name;
    bool __calculate_crc;
    VirtualPortModel __virtual_port;
    PackageTemplateManager __package_template;
    CRCModel __crc;
};

#endif // STATIONMODEL_HPP
