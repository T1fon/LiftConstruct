#include<QJsonObject>
#include<QtTest>
#include <QtSerialPort/QSerialPort>
#include "../../../../src/Model/StationModel/stationmodel.hpp"

class StationModelTest : public QObject
{
    Q_OBJECT
public:
    StationModelTest();
    ~StationModelTest();
private slots:
    void testConstructor1();
    void testGettersSetters();
    void testChangeCrc();
    void testChangeVP();
    void testChangePT();


};

StationModelTest::StationModelTest(){}
StationModelTest::~StationModelTest(){}

void StationModelTest::testConstructor1()
{
    // Создание объекта для описания виртуального COM порта
    QJsonObject virtualPort {
        {"physical_interface", "RS232"},
        {"bod", 9600},
        {"bit_of_data", 8},
        {"parity", 0},
        {"stop_bits", 1},
        {"flow_control", 0}
    };

    // Создание массива секций для шаблона пакета
    QJsonArray sectionsArray;
    QJsonObject section {
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);

    // Создание шаблона пакета
    QJsonArray packageTemplateArray;
    QJsonObject packageTemplate {
        {"id", 101},
        {"size", 10},
        {"sections", sectionsArray},
        {"description", "Standard data package"},
        {"name", "Data Pack 1"}
    };
    packageTemplateArray.append(packageTemplate);

    // Создание объекта для настройки CRC
    QJsonObject crcSettings {
        {"position_crc", 5},
        {"size_crc", 1},
        {"start_calculate_crc", 1},
        {"end_calculate_crc", 8},
        {"code", "XOR"}
    };

    // Создание основного объекта станции
    QJsonObject station {
        {"id", 1},
        {"name", "Station A"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };

    StationModel model(station);
    QJsonObject station_res = model.DumpToJson();

    QCOMPARE(station_res, station);
}

void StationModelTest::testGettersSetters()
{
    // Создание объекта для описания виртуального COM порта
    QJsonObject virtualPort {
        {"physical_interface", "RS232"},
        {"bod", 9600},
        {"bit_of_data", 8},
        {"parity", 0},
        {"stop_bits", 1},
        {"flow_control", 0}
    };

    // Создание массива секций для шаблона пакета
    QJsonArray sectionsArray;
    QJsonObject section {
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);

    // Создание шаблона пакета
    QJsonArray packageTemplateArray;
    QJsonObject packageTemplate {
        {"id", 101},
        {"size", 10},
        {"sections", sectionsArray},
        {"description", "Standard data package"},
        {"name", "Data Pack 1"}
    };
    packageTemplateArray.append(packageTemplate);

    // Создание объекта для настройки CRC
    QJsonObject crcSettings {
        {"position_crc", 5},
        {"size_crc", 1},
        {"start_calculate_crc", 1},
        {"end_calculate_crc", 8},
        {"code", "XOR"}
    };

    // Создание основного объекта станции
    QJsonObject station {
        {"id", 1},
        {"name", "Station A"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };

    StationModel model(station);
    model.changeFlag(false);
    model.ChangeName("Station B");

    PackageTemplateModel model_pt = model.getModel(101);

    QCOMPARE(model.getName(), "Station B");
    QCOMPARE(model.getFlag(), false);
    QCOMPARE(model_pt.GetName(),packageTemplate["name"].toString());
    QCOMPARE(model_pt.GetDescription(),packageTemplate["description"].toString());

}

void StationModelTest::testChangeCrc()
{
    // Создание объекта для описания виртуального COM порта
    QJsonObject virtualPort {
        {"physical_interface", "RS232"},
        {"bod", 9600},
        {"bit_of_data", 8},
        {"parity", 0},
        {"stop_bits", 1},
        {"flow_control", 0}
    };

    // Создание массива секций для шаблона пакета
    QJsonArray sectionsArray;
    QJsonObject section {
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);

    // Создание шаблона пакета
    QJsonArray packageTemplateArray;
    QJsonObject packageTemplate {
        {"id", 101},
        {"size", 10},
        {"sections", sectionsArray},
        {"description", "Standard data package"},
        {"name", "Data Pack 1"}
    };
    packageTemplateArray.append(packageTemplate);

    // Создание объекта для настройки CRC
    QJsonObject crcSettings {
        {"position_crc", 5},
        {"size_crc", 1},
        {"start_calculate_crc", 1},
        {"end_calculate_crc", 8},
        {"code", "XOR"}
    };

    // Создание основного объекта станции
    QJsonObject station {
        {"id", 1},
        {"name", "Station A"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };

    StationModel model(station);
    model.ChangeCrc(7, 8, 6, 7, "hellow");
    CRCModel crc = model.getCRC();

    QCOMPARE(crc.GetPositionCrc(), 7);
    QCOMPARE(crc.GetSizeCrc(), 8);
    QCOMPARE(crc.GetStartCalculateCrc(), 6);
    QCOMPARE(crc.GetEndCalculateCrc(), 7);
    QCOMPARE(crc.GetCode(),"hellow");
}
void StationModelTest::testChangeVP()
{
    // Создание объекта для описания виртуального COM порта
    QJsonObject virtualPort {
        {"physical_interface", "RS232"},
        {"bod", 9600},
        {"bit_of_data", 8},
        {"parity", 0},
        {"stop_bits", 1},
        {"flow_control", 0}
    };

    // Создание массива секций для шаблона пакета
    QJsonArray sectionsArray;
    QJsonObject section {
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);

    // Создание шаблона пакета
    QJsonArray packageTemplateArray;
    QJsonObject packageTemplate {
        {"id", 101},
        {"size", 10},
        {"sections", sectionsArray},
        {"description", "Standard data package"},
        {"name", "Data Pack 1"}
    };
    packageTemplateArray.append(packageTemplate);

    // Создание объекта для настройки CRC
    QJsonObject crcSettings {
        {"position_crc", 5},
        {"size_crc", 1},
        {"start_calculate_crc", 1},
        {"end_calculate_crc", 8},
        {"code", "XOR"}
    };

    // Создание основного объекта станции
    QJsonObject station {
        {"id", 1},
        {"name", "Station A"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };

    StationModel model(station);
    model.ChangeCrc(7, 8, 6, 7, "hellow");
    CRCModel crc = model.getCRC();

    QCOMPARE(crc.GetPositionCrc(), 7);
    QCOMPARE(crc.GetSizeCrc(), 8);
    QCOMPARE(crc.GetStartCalculateCrc(), 6);
    QCOMPARE(crc.GetEndCalculateCrc(), 7);
    QCOMPARE(crc.GetCode(),"hellow");

}
void StationModelTest::testChangePT()
{
    // Создание объекта для описания виртуального COM порта
    QJsonObject virtualPort {
        {"physical_interface", "RS232"},
        {"bod", 9600},
        {"bit_of_data", 8},
        {"parity", 0},
        {"stop_bits", 1},
        {"flow_control", 0}
    };

    // Создание массива секций для шаблона пакета
    QJsonArray sectionsArray;
    QJsonObject section {
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);

    // Создание шаблона пакета
    QJsonArray packageTemplateArray;
    QJsonObject packageTemplate {
        {"id", 101},
        {"size", 10},
        {"sections", sectionsArray},
        {"description", "Standard data package"},
        {"name", "Data Pack 1"}
    };
    packageTemplateArray.append(packageTemplate);

    // Создание объекта для настройки CRC
    QJsonObject crcSettings {
        {"position_crc", 5},
        {"size_crc", 1},
        {"start_calculate_crc", 1},
        {"end_calculate_crc", 8},
        {"code", "XOR"}
    };

    // Создание основного объекта станции
    QJsonObject station {
        {"id", 1},
        {"name", "Station A"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };

    StationModel model(station);
    model.ChangePackageTemplate(101, 5, "GFFGG", "fdfd");
    QJsonObject res_crc = model.DumpToJson();
    PackageTemplateModel mod = model.getModel(101);

    QCOMPARE(mod.getId(), 101);
    QCOMPARE(mod.GetSize(), 5);
    QCOMPARE(mod.GetDescription(), "GFFGG");
    QCOMPARE(mod.GetName(), "fdfd");
}
QTEST_APPLESS_MAIN(StationModelTest)

#include "StationModelTest.moc"
