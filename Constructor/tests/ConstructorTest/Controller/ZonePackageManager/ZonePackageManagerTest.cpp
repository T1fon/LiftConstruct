#include<QJsonObject>
#include <QJsonArray>
#include <QtTest>
#include "../../../../src/Controller/ZonePackageManager/zonepackagemanager.hpp"

class ZonePackageManagerTest : public QObject
{
    Q_OBJECT
public:
    ZonePackageManagerTest();
    ~ZonePackageManagerTest();
private slots:
    void testConstructor();
    void testDumpToJson();
    void testgetAllNames();
    void testGetModel1();
    void testGetModel2();
    void testChangeElement1();
    void testChangeElement2();
    void testDeleteElement1();
    void testDeleteElement2();
    void testAddElement();
};

ZonePackageManagerTest::ZonePackageManagerTest(){};
ZonePackageManagerTest::~ZonePackageManagerTest(){};

void ZonePackageManagerTest::testConstructor()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);
    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    QVector<QString> names = {"Zone 1"};

    //act

    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    QVector<QString> res_names = manager.getAllNames();

    //assert

    QCOMPARE(res_names, names);


}
void ZonePackageManagerTest::testDumpToJson()
{
    //arrange
    QJsonArray package_zones_array;
    QJsonObject zone1_object;

    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);
    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    //act

    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    QJsonObject res_json;
    res_json["package_zones"] = manager.dumpToJson();

    //assert
    QCOMPARE(res_json["id"].toInt(), final_object["id"].toInt());
    QCOMPARE(res_json["name"].toString(), final_object["name"].toString());
    QCOMPARE(res_json["color"].toString(), final_object["color"].toString());
}
void ZonePackageManagerTest::testgetAllNames()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);

    QJsonObject zone2_object;
    zone2_object["id"] = 1;
    zone2_object["name"] = "Zone 2";
    zone2_object["color"] = "#ff0000";
    package_zones_array.append(zone2_object);

    QJsonObject zone3_object;
    zone3_object["id"] = 2;
    zone3_object["name"] = "Zone 3";
    zone3_object["color"] = "#00ff00";
    package_zones_array.append(zone3_object);

    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    QVector<QString> names = {"Zone 1", "Zone 2", "Zone 3"};
    //act
    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    QVector<QString> res_names = manager.getAllNames();
    QCOMPARE(res_names, names);
}
void ZonePackageManagerTest::testGetModel1()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);

    QJsonObject zone2_object;
    zone2_object["id"] = 1;
    zone2_object["name"] = "Zone 2";
    zone2_object["color"] = "#ff0000";
    package_zones_array.append(zone2_object);

    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    //act
    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    ZonePackageModel model = manager.getModel(0);

    //assert
    QCOMPARE(model.color().name(), QString("#ffffff"));
    QCOMPARE(model.id(), 0);
    QCOMPARE(model.name(), "Zone 1");
}
void ZonePackageManagerTest::testGetModel2()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);

    QJsonObject zone2_object;
    zone2_object["id"] = 1;
    zone2_object["name"] = "Zone 2";
    zone2_object["color"] = "#ff0000";
    package_zones_array.append(zone2_object);

    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    //act
    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    ZonePackageModel model = manager.getModel("Zone 2");

    //assert
    QCOMPARE(model.color().name(), QString("#ff0000"));
    QCOMPARE(model.id(), 1);
    QCOMPARE(model.name(), "Zone 2");
}
void ZonePackageManagerTest::testChangeElement1()
{
    //arrange
    QJsonArray package_zones_array;
    QJsonObject zone1_object;

    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);
    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    //act

    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    manager.changeElement(0, "Zone 2", QColor("#fdfdfd"));
    ZonePackageModel model = manager.getModel(0);

    //assert
    QCOMPARE(model.color().name(), QString("#fdfdfd"));
    QCOMPARE(model.id(), 0);
    QCOMPARE(model.name(), "Zone 2");
}
void ZonePackageManagerTest::testChangeElement2()
{
    //arrange
    QJsonArray package_zones_array;
    QJsonObject zone1_object;

    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);
    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    //act

    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    manager.changeElement("Zone 1", QColor("#fdfdfd"));
    ZonePackageModel model = manager.getModel(0);

    //assert
    QCOMPARE(model.color().name(), QString("#fdfdfd"));
    QCOMPARE(model.id(), 0);
    QCOMPARE(model.name(), "Zone 1");
}
void ZonePackageManagerTest::testDeleteElement1()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);

    QJsonObject zone2_object;
    zone2_object["id"] = 1;
    zone2_object["name"] = "Zone 2";
    zone2_object["color"] = "#ff0000";
    package_zones_array.append(zone2_object);

    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;
    QVector<QString> names = {"Zone 2"};

    //act
    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    manager.deleteElement(0);
    QVector<QString> res_names = manager.getAllNames();
    //assert
    QCOMPARE(res_names, names);
}
void ZonePackageManagerTest::testDeleteElement2()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);

    QJsonObject zone2_object;
    zone2_object["id"] = 1;
    zone2_object["name"] = "Zone 2";
    zone2_object["color"] = "#ff0000";
    package_zones_array.append(zone2_object);

    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;
    QVector<QString> names = {"Zone 2"};

    //act
    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    manager.deleteElement("Zone 1");
    QVector<QString> res_names = manager.getAllNames();
    //assert
    QCOMPARE(res_names, names);
}
void ZonePackageManagerTest::testAddElement()
{
    //arrange
    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["name"] = "Zone 1";
    zone1_object["color"] = "#ffffff";
    package_zones_array.append(zone1_object);
    QJsonObject final_object;
    final_object["package_zones"] = package_zones_array;

    QVector<QString> names = {"Zone 1", "Zone 2"};

    //act

    ZonePackageManager& manager = ZonePackageManager::getInstance(final_object);
    manager.constructFromJson(final_object);
    manager.addElement("Zone 2", QColor("#ffffff"));
    QVector<QString> res_names = manager.getAllNames();

    //assert

    QCOMPARE(res_names, names);
}
QTEST_APPLESS_MAIN(ZonePackageManagerTest)

#include "ZonePackageManagerTest.moc"
