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
    void setSize(const size_t& size);
    const size_t& getSize();
    void addSection(const size_t& pos, const QJsonObject& json);
    void addSection(const size_t& pos,const size_t& package_zone_id, const size_t& start_position,
                    const size_t& size_section);
    void changeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position,
                                             const size_t& size_section);
    void changeSection(const size_t& size, const QString& description, const QString& name);
    void changeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position, const size_t& size_section,
                       const size_t& size, const QString& description, const QString& name);
    void deleteSection(const size_t& pos);
    QJsonObject dumpToJson();
    void constructFromJson(const QJsonObject& json);
    void setDescriotion(const QString& description);
    QString& getDescription();
    void setName(const QString& name);
    QString& getName();
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
