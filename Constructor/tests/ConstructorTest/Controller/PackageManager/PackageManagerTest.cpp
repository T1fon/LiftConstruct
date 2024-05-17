#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Controller/PackageManager/packagemanager.hpp"

class PackageManagerTest : public QObject
{
    Q_OBJECT
public:
    PackageManagerTest();
    ~PackageManagerTest();
private slots:
    void testConstruct1();
    void testDumpToJson();
    void testReturnById();
    void testReturnByName();
};

PackageManagerTest::PackageManagerTest(){}
PackageManagerTest::~PackageManagerTest(){}

void PackageManagerTest::testConstruct1()
{
    //arrange

    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["station_id"] = 5;
    zone1_object["package_template_id"] = 7;
    zone1_object["name"] = "Zone 1";
    zone1_object["data"] = "0101010";
    zone1_object["description"] = "description";
    package_zones_array.append(zone1_object);
    QVector<uint8_t> vect = {0,1,0,1,0,1,0};

    QJsonObject final_object;
    final_object["packages"] = package_zones_array;

    //act
    PackageManager& manager = PackageManager::getInstance(final_object);
    manager.ConstructFromJson(final_object);
    PackageModel model = manager.ReturnById(0);

    //assert

    QCOMPARE(model.GetId(), zone1_object["id"].toInt());
    QCOMPARE(model.GetStationId(), zone1_object["station_id"].toInt());
    QCOMPARE(model.GetPackageTemplateId(), zone1_object["package_template_id"].toInt());
    QCOMPARE(model.GetName(), zone1_object["name"].toString());
    QCOMPARE(model.GetData(), vect);
    QCOMPARE(model.GetDescription(), zone1_object["description"].toString());
}
void PackageManagerTest::testDumpToJson()
{
    //arrange

    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["station_id"] = 5;
    zone1_object["package_template_id"] = 7;
    zone1_object["name"] = "Zone 1";
    zone1_object["data"] = "0101010";
    zone1_object["description"] = "description";
    package_zones_array.append(zone1_object);

    QJsonObject final_object;
    final_object["packages"] = package_zones_array;

    //act
    PackageManager& manager = PackageManager::getInstance(final_object);
    manager.ConstructFromJson(final_object);
    QJsonObject model;
    model["packages"] = manager.DumpToJson();

    //assert

    QCOMPARE(model, final_object);
}
void PackageManagerTest::testReturnById()
{
    //arrange

    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["station_id"] = 5;
    zone1_object["package_template_id"] = 7;
    zone1_object["name"] = "Zone 1";
    zone1_object["data"] = "0101010";
    zone1_object["description"] = "description";
    package_zones_array.append(zone1_object);
    QVector<uint8_t> vect = {0,1,0,1,0,1,0};

    QJsonObject final_object;
    final_object["packages"] = package_zones_array;

    //act
    PackageManager& manager = PackageManager::getInstance(final_object);
    manager.ConstructFromJson(final_object);
    PackageModel model = manager.ReturnById(0);

    //assert

    QCOMPARE(model.GetId(), zone1_object["id"].toInt());
    QCOMPARE(model.GetStationId(), zone1_object["station_id"].toInt());
    QCOMPARE(model.GetPackageTemplateId(), zone1_object["package_template_id"].toInt());
    QCOMPARE(model.GetName(), zone1_object["name"].toString());
    QCOMPARE(model.GetData(), vect);
    QCOMPARE(model.GetDescription(), zone1_object["description"].toString());
}
void PackageManagerTest::testReturnByName()
{
    //arrange

    QJsonArray package_zones_array;

    QJsonObject zone1_object;
    zone1_object["id"] = 0;
    zone1_object["station_id"] = 5;
    zone1_object["package_template_id"] = 7;
    zone1_object["name"] = "Zone 1";
    zone1_object["data"] = "0101010";
    zone1_object["description"] = "description";
    package_zones_array.append(zone1_object);
    QVector<uint8_t> vect = {0,1,0,1,0,1,0};

    QJsonObject final_object;
    final_object["packages"] = package_zones_array;

    //act
    PackageManager& manager = PackageManager::getInstance(final_object);
    manager.ConstructFromJson(final_object);
    PackageModel model = manager.ReturnByName("Zone 1");

    //assert

    QCOMPARE(model.GetId(), zone1_object["id"].toInt());
    QCOMPARE(model.GetStationId(), zone1_object["station_id"].toInt());
    QCOMPARE(model.GetPackageTemplateId(), zone1_object["package_template_id"].toInt());
    QCOMPARE(model.GetName(), zone1_object["name"].toString());
    QCOMPARE(model.GetData(), vect);
    QCOMPARE(model.GetDescription(), zone1_object["description"].toString());
}

QTEST_APPLESS_MAIN(PackageManagerTest)

#include "PackageManagerTest.moc"
