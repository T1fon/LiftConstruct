#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/SectionModel/sectionmodel.hpp"

class SectionModelTest : public QObject
{
    Q_OBJECT
public:
    SectionModelTest();
    ~SectionModelTest();
public slots:
    void testConstruct1();
    void testConstruct2();
    void testConstruct3();
    void testSettersGetters();
    void testDumpToJson();
    void testConstructFromJson();
private:
    QDir __directory;
};

SectionModelTest::SectionModelTest(){}
SectionModelTest::~SectionModelTest(){}
void SectionModelTest::testConstruct1()
{
    //arrange
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model(1,1,2);
    int test_pac = model.GetPackageZoneId();
    int test_start = model.GetStartPosition();
    int test_size = model.GetSizeStation();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}

void SectionModelTest::testConstruct2()
{
    //arrange
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model_test(1,1,2);
    SectionModel model(model_test);
    int test_pac = model.GetPackageZoneId();
    int test_start = model.GetStartPosition();
    int test_size = model.GetSizeStation();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}
void SectionModelTest::testConstruct3()
{
    //arrange
    QJsonObject testJson
    {
        { "package_zone_id", 1 },
        { "start_position", 1 },
        { "size_section", 2 }
    };
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model(testJson);
    int test_pac = model.GetPackageZoneId();
    int test_start = model.GetStartPosition();
    int test_size = model.GetSizeStation();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}

void SectionModelTest::testSettersGetters()
{
    //arrange
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model(0,0,0);
    model.SetPackageZoneId(1);
    model.SetStartPosition(1);
    model.SetSizeStation(2);
    int test_pac = model.GetPackageZoneId();
    int test_start = model.GetStartPosition();
    int test_size = model.GetSizeStation();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}

void SectionModelTest::testConstructFromJson()
{
    //arrange
    QJsonObject testJson
        {
            { "package_zone_id", 1 },
            { "start_position", 1 },
            { "size_section", 2 }
        };
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model(testJson);
    int test_pac = model.GetPackageZoneId();
    int test_start = model.GetStartPosition();
    int test_size = model.GetSizeStation();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}

void SectionModelTest::testDumpToJson()
{
    //arrange
    QJsonObject testJson
        {
            { "package_zone_id", 1 },
            { "start_position", 1 },
            { "size_section", 2 }
        };
    int package_zone_id = 1,start_position = 1, size_section = 2;
    //act
    SectionModel model(testJson);
    QJsonObject t_j = model.toJson();
    int test_pac = t_j["package_zone_id"].toInt();
    int test_start = t_j["start_position"].toInt();
    int test_size = t_j["size_section"].toInt();
    //assert
    QCOMPARE(test_pac,package_zone_id);
    QCOMPARE(test_start, start_position);
    QCOMPARE(test_size, size_section);
}
