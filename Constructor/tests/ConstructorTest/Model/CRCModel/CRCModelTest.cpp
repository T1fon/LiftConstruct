#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/CRCModel/crcmodel.hpp"

class CRCModelTest : public QObject
{
    Q_OBJECT
public:
    CRCModelTest();
    ~CRCModelTest();
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

CRCModelTest::CRCModelTest(){};
CRCModelTest::~CRCModelTest(){};

void CRCModelTest::testConstruct1()
{
    //arrange
    int position_crc = 1, size_crc = 7, start_calculate_crc = 1, end_calculate_crc = 5;
    QString code = "abcd";
    //act
    CRCModel a(1, 7, 1, 5, "abcd");
    int test_pos = a.GetPositionCrc();
    int test_size = a.GetSizeCrc();
    int test_start = a.GetStartCalculateCrc();
    int test_end = a.GetEndCalculateCrc();
    QString test_code = a.GetCode();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);

}

void CRCModelTest::testConstruct2()
{
    //arrange
    int position_crc = 1, size_crc = 7, start_calculate_crc = 1, end_calculate_crc = 5;
    QString code = "abcd";
    //act
    CRCModel a(1, 7, 1, 5, "abcd");
    CRCModel model(a);
    int test_pos = model.GetPositionCrc();
    int test_size = model.GetSizeCrc();
    int test_start = model.GetStartCalculateCrc();
    int test_end = model.GetEndCalculateCrc();
    QString test_code = model.GetCode();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);
}

void CRCModelTest::testConstruct3()
{
    //arrange
    QJsonObject json = {
        { "position_crc", 1 },
        { "size_crc", 5 },
        { "start_calculate_crc", 2 },
        { "end_calculate_crc", 3},
        { "code", "abcd"}
    };
    int position_crc = 1, size_crc = 5, start_calculate_crc = 2, end_calculate_crc = 3;
    QString code = "abcd";
    //act
    CRCModel model(json);
    int test_pos = model.GetPositionCrc();
    int test_size = model.GetSizeCrc();
    int test_start = model.GetStartCalculateCrc();
    int test_end = model.GetEndCalculateCrc();
    QString test_code = model.GetCode();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);
}

void CRCModelTest::testConstructFromJson()
{
    //arrange
    QJsonObject json = {
        { "position_crc", 1 },
        { "size_crc", 5 },
        { "start_calculate_crc", 2 },
        { "end_calculate_crc", 3},
        { "code", "abcd"}
    };
    int position_crc = 1, size_crc = 5, start_calculate_crc = 2, end_calculate_crc = 3;
    QString code = "abcd";
    //act
    CRCModel model(0,0,0,0,"");
    model.ConstructFromJson(json);
    int test_pos = model.GetPositionCrc();
    int test_size = model.GetSizeCrc();
    int test_start = model.GetStartCalculateCrc();
    int test_end = model.GetEndCalculateCrc();
    QString test_code = model.GetCode();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);
}

void CRCModelTest::testDumpToJson()
{
    //arrange
    QJsonObject json = {
        { "position_crc", 1 },
        { "size_crc", 5 },
        { "start_calculate_crc", 2 },
        { "end_calculate_crc", 3},
        { "code", "abcd"}
    };
    int position_crc = 1, size_crc = 5, start_calculate_crc = 2, end_calculate_crc = 3;
    QString code = "abcd";
    //act
    CRCModel model(json);
    QJsonObject t_j = model.toJson();
    int test_pos = t_j["position_crc"].toInt();
    int test_size = t_j["size_crc"].toInt();
    int test_start = t_j["start_calculate_crc"].toInt();
    int test_end = t_j["end_calculate_crc"].toInt();
    QString test_code = t_j["code"].toString();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);
}

void CRCModelTest::testSettersGetters()
{
    //arrange
    int position_crc = 1, size_crc = 7, start_calculate_crc = 1, end_calculate_crc = 5;
    QString code = "abcd";
    //act
    CRCModel model(0,0,0,0,"");
    model.SetCode("abcd");
    model.SetEndCalculateCrc(5);
    model.SetStartCalculateCrc(1);
    model.SetSizeCrc(7);
    model.SetPositionCrc(1);
    int test_pos = model.GetPositionCrc();
    int test_size = model.GetSizeCrc();
    int test_start = model.GetStartCalculateCrc();
    int test_end = model.GetEndCalculateCrc();
    QString test_code = model.GetCode();
    //assert
    QCOMPARE(test_pos,position_crc);
    QCOMPARE(test_size,size_crc);
    QCOMPARE(test_start,start_calculate_crc);
    QCOMPARE(test_end,end_calculate_crc);
    QCOMPARE(test_code,code);
}
