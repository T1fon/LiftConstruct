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
    PackageTemplateModel(const size_t& size, const QString& description, const QString& name);
    void SetSize(const size_t& size);
    const size_t& GetSize();
    void addSection(const size_t& pos, const QJsonObject& json);
    void addSection(const size_t& pos,const size_t& package_zone_id, const size_t& start_position,
                    const size_t& size_section);
    void ChangeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position,
                                             const size_t& size_section);
    void ChangeSection(const size_t& size, const QString& description, const QString& name);
    void ChangeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position, const size_t& size_section,
                       const size_t& size, const QString& description, const QString& name);
    void DeleteSection(const size_t& pos);
    QJsonObject DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
    void SetDescriotion(const QString& description);
    QString& GetDescription();
    void SetName(const QString& name);
    QString& GetName();
    size_t& getId();
    SectionManager& getSection();
    void setSection(const SectionManager& section);


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
