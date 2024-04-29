#ifndef PACKAGETEMPLATEMODEL_HPP
#define PACKAGETEMPLATEMODEL_HPP

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "../../Controller/SectionManager/sectionmanager.hpp"

class PackageTemplateModel
{
public:
    PackageTemplateModel(const QJsonObject& json);
    void SetSize(size_t size);
    size_t GetSize();
    void AddSection(size_t pos, QJsonObject& json);
    void ChangeSection(size_t pos, int package_zone_id, int start_position, int size_section);
    void DeleteSection(size_t pos);
    QJsonObject DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
    void SetDescriotion(QString description);
    QString GetDescription();

private:
    size_t __id;
    size_t __size;
    SectionManager __sections;
    QString __description;
    QString __name;
    static size_t __last_id;
    void __ErrorMsg(QString target);
};

#endif // PACKAGETEMPLATEMODEL_HPP
