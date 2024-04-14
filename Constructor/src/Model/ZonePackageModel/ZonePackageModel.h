#ifndef ZONEPACKAGEMODEL_H
#define ZONEPACKAGEMODEL_H

#include <QColor>
#include <QJsonObject>
class ZonePackageModel
{
public:
    static const QString DEF_JSON_FIELD_VAL_ID;
    static const QString DEF_JSON_FIELD_VAL_NAME;
    static const QString DEF_JSON_FIELD_VAL_COLOR;
    static const QString DEF_COLOR_VALUE;
    ZonePackageModel();
    ZonePackageModel(const ZonePackageModel &value);
    ZonePackageModel(const size_t &id,const QString &name, const QColor &color);
    ZonePackageModel(const QString &name, const QColor &color);
    ZonePackageModel(const QJsonObject &value);

    void setName(const QString &name);
    void setColor(const QColor &color);

    QString name();
    QColor color();
    size_t id();

    QJsonObject toJsonObject();

    ZonePackageModel& operator=(ZonePackageModel& value);
    bool operator<(ZonePackageModel& value);
    bool operator==(ZonePackageModel& value);
private:
    size_t __id;
    QString __name;
    QColor __color;
    static size_t __id_max;
};

#endif // ZONEPACKAGEMODEL_H
