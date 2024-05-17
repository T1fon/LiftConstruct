#ifndef PACKAGETEMPLATEMANAGER_HPP
#define PACKAGETEMPLATEMANAGER_HPP

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "../../Model/PackageTemplateModel/packagetemplatemodel.hpp"


class PackageTemplateManager : public QObject
{
    Q_OBJECT
public:
    PackageTemplateManager(const QJsonObject& json);
    PackageTemplateManager();
    QJsonArray DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
    void AddSample(const QJsonObject& json);
    void ChangeElement(const QString& name, const size_t& size, const QString& description);
    void ChangeElement(const QString& name,const size_t& pos_section,
           const size_t& package_sone_id, const size_t& start_postition, const size_t& size_section);
    void ChangeElement(const size_t& id, const QString& name, const size_t& size, const QString& description);
    void ChangeElement(const size_t& id, const size_t& pos_section,
            const size_t& package_sone_id, const size_t& start_postition, const size_t& size_section);
    void DeleteElement(const size_t& id);
    void DeleteElement(const QString& name);
    size_t getSize();
    PackageTemplateModel& getModel(const size_t& id);
private:
    QVector<PackageTemplateModel> __models;
signals:
    void PackageTemplateAdded(size_t size);
    void PackageTempalteChange(size_t pos);
    void PackageTemplateDeleted(size_t pos);
};

#endif // PACKAGETEMPLATEMANAGER_HPP
