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
    int GetTotalSize();
    void AddSection(size_t pos, QJsonObject& json);
    void ChangeSection(size_t pos, int package_zone_id, int start_position, int size_section);
    void DeleteSection(size_t pos);
    size_t SearchSection(size_t pos);
    const QVector<SectionModel>& GetSections() const;
    QJsonObject DumpToJson();
    void ConstructFromJson(const QJsonObject& json);
private:
    QVector<SectionModel> __sections;
    size_t __total_size;
    void __ErrorMsg(QString target);
    SectionModel __buf_model;
signals:
    void SectionChanged(int position);
    void SectionDeleted(int position);

};

#endif // SECTIONMANAGER_HPP
