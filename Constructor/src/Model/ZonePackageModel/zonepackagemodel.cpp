#include "zonepackagemodel.hpp"
size_t ZonePackageModel::__id_max = 0;
const QString ZonePackageModel::DEF_JSON_FIELD_VAL_ID = "id";
const QString ZonePackageModel::DEF_JSON_FIELD_VAL_NAME = "name";
const QString ZonePackageModel::DEF_JSON_FIELD_VAL_COLOR = "color";
const QString ZonePackageModel::DEF_COLOR_VALUE = "#ffffff";
ZonePackageModel::ZonePackageModel()
{
    __id = __id_max;
    __id_max++;
    __name = "";
    __color = QColor();
}
ZonePackageModel::ZonePackageModel(const ZonePackageModel &value)
{
    __id = value.__id;
    __name = value.__name;
    __color = value.__color;
}
ZonePackageModel::ZonePackageModel(const size_t &id,const QString &name, const QColor &color)
{
    if(__id_max < id){__id_max = id;}
    __id = __id_max;
    __id_max++;
    __name = name;
    __color = color;
}
ZonePackageModel::ZonePackageModel(const QString &name, const QColor &color)
{
    __id = __id_max;
    __id_max++;
    __name = name;
    __color = color;
}
ZonePackageModel::ZonePackageModel(const QJsonObject &value)
{
    __id = value[DEF_JSON_FIELD_VAL_ID].toInteger(__id_max);
    if(__id_max < __id){__id_max = __id;}
    __name = value[DEF_JSON_FIELD_VAL_NAME].toString("");
    __color = QColor(value[DEF_JSON_FIELD_VAL_COLOR].toString(DEF_COLOR_VALUE));
}

void ZonePackageModel::setName(const QString &name){__name = name;}
void ZonePackageModel::setColor(const QColor &color){__color = color;}
QString& ZonePackageModel::getName(){return __name;}
QColor& ZonePackageModel::getColor(){return __color;}
size_t& ZonePackageModel::getId(){return __id;}

QString ZonePackageModel::name(){return __name;}
QColor ZonePackageModel::color(){return __color;}
size_t ZonePackageModel::id(){return __id;}

QJsonObject ZonePackageModel::toJsonObject()
{
    QJsonObject result;
    result[DEF_JSON_FIELD_VAL_ID] = (qint64)__id;
    result[DEF_JSON_FIELD_VAL_ID] = __name;
    result[DEF_JSON_FIELD_VAL_ID] = __color.name(QColor::NameFormat::HexRgb);
    return result;
}

ZonePackageModel& ZonePackageModel::operator=(ZonePackageModel& value)
{
    __id = value.__id;
    __name = value.__name;
    __color = value.__color;
    return *this;
}
bool ZonePackageModel::operator<(ZonePackageModel& value)
{
    return __id < value.__id;
}
bool ZonePackageModel::operator==(ZonePackageModel& value)
{
    return __id == value.__id && __name == value.__name && __color == value.__color;
}
