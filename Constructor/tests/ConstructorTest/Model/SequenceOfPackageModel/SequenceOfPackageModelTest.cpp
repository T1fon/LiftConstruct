#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/SequenceOfPackageModel/sequenceofpackagemodel.hpp"

class SequenceOfPackageModelTest : public QObject
{
    Q_OBJECT
public:
    SequenceOfPackageModelTest();
    ~SequenceOfPackageModelTest();
public slots:
    void testConstruct1();
    void testSettersGetters();
    void testDumpToJson();
    void testConstructFromJson();
};

SequenceOfPackageModelTest::SequenceOfPackageModelTest(){}
SequenceOfPackageModelTest::~SequenceOfPackageModelTest(){}

void SequenceOfPackageModelTest::testConstruct1()
{
    //arrange
    QJsonObject json =
    {
        {"position", 5},
        {"package_id", 1},
        {"action", 0}
    };
    int position = 5, package_id = 1, action = 0;

    //act
    SequenceOfPackageModel model(json);
    int test_pos = model.GetPosition();
    int test_package_id = model.GetPackageId();
    int test_action = model.GetAction();

    //assert
    QCOMPARE(test_pos,position);
    QCOMPARE(test_package_id,package_id);
    QCOMPARE(test_action,action);

}

void SequenceOfPackageModelTest::testConstructFromJson()
{
    //arrange
    QJsonObject buf_json =
        {
            {"position", 5},
            {"package_id", 1},
            {"action", 0}
        };
    QJsonObject json =
        {
            {"position", 5},
            {"package_id", 9},
            {"action", 1}
        };
    int position = 5, package_id = 9, action = 1;

    //act
    SequenceOfPackageModel model(buf_json);
    model.ConstructFromJson(json);
    int test_pos = model.GetPosition();
    int test_package_id = model.GetPackageId();
    int test_action = model.GetAction();

    //assert
    QCOMPARE(test_pos,position);
    QCOMPARE(test_package_id,package_id);
    QCOMPARE(test_action,action);

}

void SequenceOfPackageModelTest::testSettersGetters()
{
    //arramge
    QJsonObject json =
        {
            {"position", 5},
            {"package_id", 9},
            {"action", 1}
        };
    int position = 1, package_id = 3, action = 0;

    //act
    SequenceOfPackageModel model(json);
    model.SetAction(0);
    model.SetPackageId(3);
    model.SetPosition(1);
    int test_pos = model.GetPosition();
    int test_package_id = model.GetPackageId();
    int test_action = model.GetAction();

    //assert
    QCOMPARE(test_pos,position);
    QCOMPARE(test_package_id,package_id);
    QCOMPARE(test_action,action);
}

void SequenceOfPackageModelTest::testDumpToJson()
{
    //arramge
    QJsonObject json =
        {
            {"position", 5},
            {"package_id", 9},
            {"action", 1}
        };
    int position = 5, package_id = 9, action = 1;

    //act
    SequenceOfPackageModel model(json);
    QJsonObject j_t = model.DumpToJson();
    int test_pos = j_t["position"].toInt();
    int test_package_id = j_t["package_id"].toInt();
    int test_action = j_t["action"].toInt();

    //assert
    QCOMPARE(test_pos,position);
    QCOMPARE(test_package_id,package_id);
    QCOMPARE(test_action,action);
}
