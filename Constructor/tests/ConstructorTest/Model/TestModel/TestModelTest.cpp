#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/TestModel/testmodel.hpp"

class TestModelTest : public QObject
{
    Q_OBJECT
public:
    TestModelTest();
    ~TestModelTest();
private slots:
    void testConstructor1();
    void testConstructor2();
    void testDumpToJson();
};

TestModelTest::TestModelTest(){}
TestModelTest::~TestModelTest(){}

void TestModelTest::testConstructor1()
{
    //arrange
    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 0;
    test1["sequence_of_packages"] = QJsonArray{
        QJsonObject{
            {"position", 0},
            {"package_id", 0},
            {"action", 0}
        }
    };
    test1["description"] = "Description of Test 1";
    //act
    TestModel model(test1);

    //assert
    QCOMPARE(model.GetId(), test1["id"].toInt());
    QCOMPARE(model.GetName(), test1["name"].toString());
    QCOMPARE(model.GetStationId(), test1["station_id"].toInt());
    QCOMPARE(model.GetDescription(), test1["description"].toString());
}
void TestModelTest::testConstructor2()
{
    //arrange
    QString name = "abab";
    size_t station_id = 5;
    QString description = "ffsfds";
    QVector<SequenceOfPackageModel> model;
    model.emplace_back(SequenceOfPackageModel(0,0,0));

    //act
    TestModel as(name, station_id, model, description);

    //assert
    QCOMPARE(as.GetName(), name);
    QCOMPARE(as.GetStationId(), station_id);
    QCOMPARE(as.GetDescription(), description);
}
void TestModelTest::testDumpToJson()
{
    //arrange
    QJsonObject test1;
    test1["id"] = 0;
    test1["name"] = "Test 1";
    test1["station_id"] = 0;
    test1["sequence_of_packages"] = QJsonArray{
        QJsonObject{
            {"position", 0},
            {"package_id", 0},
            {"action", 0}
        }
    };
    test1["description"] = "Description of Test 1";
    //act
    TestModel model(test1);
    QJsonObject test_json = model.DumpToJson();

    //assert
    QCOMPARE(test_json["id"].toInt(), test1["id"].toInt());
    QCOMPARE(test_json["name"].toString(), test1["name"].toString());
    QCOMPARE(test_json["station_id"].toInt(), test1["station_id"].toInt());
    QCOMPARE(test_json["description"].toString(), test1["description"].toString());
}

QTEST_APPLESS_MAIN(TestModelTest)

#include "TestModelTest.moc"
