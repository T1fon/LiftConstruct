#ifndef SECTIONMANAGER_HPP
#define SECTIONMANAGER_HPP

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include "../../Model/SectionModel/sectionmodel.hpp"

class SectionManager : public QObject
{
    Q_OBJECT
public:
    SectionManager(const QJsonObject& json);
    SectionManager(const SectionManager& other);
    SectionManager& operator=(const SectionManager& other);
    int GetTotalSize();
    void addSection(const size_t& pos, const QJsonObject& json);
    void addSection(const size_t& package_zone_id, const size_t& start_postition, const size_t& size_section);
    void ChangeSection(const size_t& pos, const size_t& package_zone_id, const size_t& start_position, const size_t& size_section);
    void DeleteSection(const size_t& pos);
    size_t SearchSection(const size_t& pos);
    SectionModel& getModel(const size_t& pos);
    void setModel(const size_t& pos,  const SectionModel& model);
    const QVector<SectionModel>& GetSections() const;
    QJsonArray DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
private:
    QVector<SectionModel> __sections;
    size_t __total_size;
    void __ErrorMsg(QString target);
signals:
    void SectionAdded(int size);
    void SectionChanged(int position);
    void SectionDeleted(int position);

};

#endif // SECTIONMANAGER_HPP
