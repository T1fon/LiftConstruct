#include<QJsonObject>
#include<QtTest>
#include <QtSerialPort/QSerialPort>
#include "../../../../src/Controller/StationManager/stationmanager.hpp"

class StationManagerTest : public QObject
{
    Q_OBJECT
public:
    StationManagerTest();
    ~StationManagerTest();
private slots:
    void testConstructor1();
    void testChangeModel1();
    void testChangeModel2();
    void testDeleteModel1();
    void testDeleteModel2();
    //void testChangeVP();
    void testChangePT();
    void testChangeCRC();
    void testChangePT_s();
    void testAddPT_s();
    void testDeletePT_s();
    //void testAddModel();
};

StationManagerTest::StationManagerTest(){}
StationManagerTest::~StationManagerTest(){}

void StationManagerTest::testConstructor1()
{
    //arrange
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
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    QJsonArray res_array = manager.DumpToJson();
    QJsonObject res_json;
    res_json["station"] = res_array;

    //assert
    QCOMPARE(res_json, rootObject);
}

void StationManagerTest::testChangeModel1()
{
    //arrange
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
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.changeModel("Station A", false);
    StationModel& mod = manager.getModel(1);

    //assert

    QCOMPARE(mod.getFlag(), false);

}
void StationManagerTest::testChangeModel2()
{
    //arrange
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
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);
    manager.changeModel(1, "Station B", false);
    StationModel& mod = manager.getModel(1);

    //assert

    QCOMPARE(mod.getFlag(), false);
    QCOMPARE(mod.getName(), "Station B");

}

void StationManagerTest::testDeleteModel1()
{
    //arrange
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.deleteModel(2);

    QCOMPARE(manager.getSize(), 1);
}
void StationManagerTest::testDeleteModel2()
{
    //arrange
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.deleteModel("Station B");

    QCOMPARE(manager.getSize(), 1);
}
/*void StationManagerTest::testChangeVP()
{
    //arrange
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
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);



    QCOMPARE(manager.getSize(), 1);
}*/
void StationManagerTest::testChangePT()
{
    //arrange
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.changePackageTemplate(1, 101, 15, "hellow", "balabolka");
    PackageTemplateModel mod = manager.getModel(1).getModel(101);

    //assert
    QCOMPARE(mod.GetName(), "balabolka");
    QCOMPARE(mod.GetDescription(), "hellow");
    QCOMPARE(mod.GetSize(), 15);
}
void StationManagerTest::testChangeCRC()
{
    //arrange
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.changeCrc(1, 8, 20, 1, 3, "ffff");
    CRCModel mod = manager.getModel(1).getCRC();

    //assert

    QCOMPARE(mod.GetPositionCrc(), 8);
    QCOMPARE(mod.GetSizeCrc(), 20);
    QCOMPARE(mod.GetStartCalculateCrc(), 1);
    QCOMPARE(mod.GetEndCalculateCrc(), 3);
    QCOMPARE(mod.GetCode(), "ffff");
}
void StationManagerTest::testChangePT_s()
{
    //arrange
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.changePackageTemplateSection(1, 101, 0, 8, 1, 4);
    PackageTemplateModel mod = manager.getModel(1).getModel(101);

    QVector<SectionModel> vect = mod.getSection().GetSections();

    //assert
    QCOMPARE(vect[0].GetPackageZoneId(), 8);
    QCOMPARE(vect[0].GetStartPosition(), 1);
    QCOMPARE(vect[0].GetSizeStation(), 4);
}
void StationManagerTest::testAddPT_s()
{

    //arrange
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
    QJsonObject section1{
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);
    sectionsArray.append(section1);
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.addPackageTemplateSection(1, 101, 3, 15, 7, 1);
    PackageTemplateModel mod = manager.getModel(1).getModel(101);

    QVector<SectionModel> vect = mod.getSection().GetSections();


    //assert
    QCOMPARE(vect.size(), 3);
}

void StationManagerTest::testDeletePT_s()
{
    //arrange
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
    QJsonObject section1{
        {"package_zone_id", 5},
        {"start_position", 0},
        {"size_section", 3}
    };
    sectionsArray.append(section);
    sectionsArray.append(section1);
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
    QJsonObject station1 {
        {"id", 2},
        {"name", "Station B"},
        {"calculate_crc", true},
        {"virtual_port", virtualPort},
        {"package_template", packageTemplateArray},
        {"crc", crcSettings}
    };
    // Создание главного массива станций и добавление в него станции
    QJsonArray stations;
    stations.append(station);
    stations.append(station1);

    // Создание корневого объекта JSON и добавление в него массива станций
    QJsonObject rootObject;
    rootObject["station"] = stations;

    //act

    StationManager& manager = StationManager::getInstance(rootObject);
    manager.constructFromJson(rootObject);

    manager.deletePackageTemplateSection(1, 101, 1);
    PackageTemplateModel mod = manager.getModel(1).getModel(101);

    QVector<SectionModel> vect = mod.getSection().GetSections();


    //assert
    QCOMPARE(vect.size(), 1);
}

QTEST_APPLESS_MAIN(StationManagerTest)

#include "StationManagerTest.moc"
