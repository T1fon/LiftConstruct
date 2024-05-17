#include<QJsonObject>
#include <QJsonArray>
#include <QtTest>
#include "../../../../src/Controller/TestManager/testmanager.hpp"

class TestManagerTest : public QObject
{
    Q_OBJECT
public:
    TestManagerTest();
    ~TestManagerTest();
private slots:
    void testConstructor();
    void testDumpToJson();
    void testReturnByPos();
    void testReturnById();
};

TestManagerTest::TestManagerTest(){}
TestManagerTest::~TestManagerTest(){}

void TestManagerTest::testConstructor()
{

    //arrange
    QJsonArray testsArray;

    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 1;

    QJsonArray sequence1Array;
    QJsonObject package1;
    package1["position"] = 0;
    package1["package_id"] = 101;
    package1["action"] = 0;
    sequence1Array.append(package1);

    QJsonObject package2;
    package2["position"] = 1;
    package2["package_id"] = 102;
    package2["action"] = 1;
    sequence1Array.append(package2);

    test1["sequence_of_packages"] = sequence1Array;
    test1["description"] = "This is the first test";

    testsArray.append(test1);
    QJsonObject mainObject;
    mainObject["tests"] = testsArray;

    //act

    TestManager&  manager = TestManager::getInstance(mainObject);
    QJsonObject test_json;
    test_json["tests"] = manager.DumpToJson();

    //assert

    QCOMPARE(mainObject, test_json);
}


void TestManagerTest::testDumpToJson()
{
    //arrange
    QJsonArray testsArray;

    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 1;

    QJsonArray sequence1Array;
    QJsonObject package1;
    package1["position"] = 0;
    package1["package_id"] = 101;
    package1["action"] = 0;
    sequence1Array.append(package1);

    QJsonObject package2;
    package2["position"] = 1;
    package2["package_id"] = 102;
    package2["action"] = 1;
    sequence1Array.append(package2);

    test1["sequence_of_packages"] = sequence1Array;
    test1["description"] = "This is the first test";

    testsArray.append(test1);
    QJsonObject mainObject;
    mainObject["tests"] = testsArray;

    //act

    TestManager&  manager = TestManager::getInstance(mainObject);
    QJsonObject test_json;
    test_json["tests"] = manager.DumpToJson();

    //assert

    QCOMPARE(mainObject, test_json);
}
void TestManagerTest::testReturnByPos()
{
    //arrange

    QJsonArray testsArray;

    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 1;
    test1["description"] = "This is the first test";

    QJsonArray sequence1Array;
    QJsonObject package1;
    package1["position"] = 0;
    package1["package_id"] = 101;
    package1["action"] = 0;
    sequence1Array.append(package1);

    QJsonObject package2;
    package2["position"] = 1;
    package2["package_id"] = 102;
    package2["action"] = 1;
    sequence1Array.append(package2);

    test1["sequence_of_packages"] = sequence1Array;

    testsArray.append(test1);

    QJsonObject test2;
    test2["id"] = 1;
    test2["name"] = "Test 2";
    test2["station_id"] = 2;
    test2["description"] = "This is the second test";

    QJsonArray sequence2Array;
    QJsonObject package3;
    package3["position"] = 0;
    package3["package_id"] = 104;
    package3["action"] = 1;
    sequence2Array.append(package3);

    QJsonObject package4;
    package4["position"] = 1;
    package4["package_id"] = 105;
    package4["action"] = 0;
    sequence2Array.append(package4);

    test2["sequence_of_packages"] = sequence2Array;

    testsArray.append(test2);

    QJsonObject mainObject;
    mainObject["tests"] = testsArray;

    //act

    TestManager& manager = TestManager::getInstance(mainObject);
    manager.ConstructFromJson(mainObject);

    TestModel model = manager.GetTestById(0);

    //assert


    QCOMPARE(model.GetId(), test1["id"].toInt());
    QCOMPARE(model.GetName(), test1["name"].toString());
    QCOMPARE(model.GetStationId(), test1["station_id"].toInt());
    QCOMPARE(model.GetDescription(), test1["description"].toString());
}
void TestManagerTest::testReturnById()
{
    //arrange

    QJsonArray testsArray;

    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 1;
    test1["description"] = "This is the first test";

    QJsonArray sequence1Array;
    QJsonObject package1;
    package1["position"] = 0;
    package1["package_id"] = 101;
    package1["action"] = 0;
    sequence1Array.append(package1);

    QJsonObject package2;
    package2["position"] = 1;
    package2["package_id"] = 102;
    package2["action"] = 1;
    sequence1Array.append(package2);

    test1["sequence_of_packages"] = sequence1Array;

    testsArray.append(test1);

    QJsonObject test2;
    test2["id"] = 1;
    test2["name"] = "Test 2";
    test2["station_id"] = 2;
    test2["description"] = "This is the second test";

    QJsonArray sequence2Array;
    QJsonObject package3;
    package3["position"] = 0;
    package3["package_id"] = 104;
    package3["action"] = 1;
    sequence2Array.append(package3);

    QJsonObject package4;
    package4["position"] = 1;
    package4["package_id"] = 105;
    package4["action"] = 0;
    sequence2Array.append(package4);

    test2["sequence_of_packages"] = sequence2Array;

    testsArray.append(test2);

    QJsonObject mainObject;
    mainObject["tests"] = testsArray;

    //act

    TestManager& manager = TestManager::getInstance(mainObject);
    manager.ConstructFromJson(mainObject);

    TestModel model = manager.GetTestByName("Test 2");

    //assert


    QCOMPARE(model.GetId(), test2["id"].toInt());
    QCOMPARE(model.GetName(), test2["name"].toString());
    QCOMPARE(model.GetStationId(), test2["station_id"].toInt());
    QCOMPARE(model.GetDescription(), test2["description"].toString());
}

QTEST_APPLESS_MAIN(TestManagerTest)

#include "TestManagerTest.moc"
