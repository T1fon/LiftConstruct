#include<QJsonObject>
#include <QJsonArray>
#include <QtTest>
#include "../../../../src/Controller/SequenceOfPackageManager/sequenceofpackagemanager.hpp"

class SequenceOfPackageManagerTest : public QObject
{
    Q_OBJECT
public:
    SequenceOfPackageManagerTest();
    ~SequenceOfPackageManagerTest();
private slots:
    void testConstructor();
    void testConstructFromJson();
    void testDumpToJson();
    void testReturnByPos();
    void testReturnById();
};

SequenceOfPackageManagerTest::SequenceOfPackageManagerTest(){}
SequenceOfPackageManagerTest::~SequenceOfPackageManagerTest(){}

void SequenceOfPackageManagerTest::testConstructor()
{
    // Arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"position", 0},
            {"package_id", 1},
            {"action", 0}
        };
    json_array.append(package1);
    json_obj["sequence_of_packages"] = json_array;

    int expected_position = 0;
    int expected_package_id = 1;
    int expected_action = 0;

    // Act
    SequenceOfPackageManager manager(json_obj);
    SequenceOfPackageModel model(manager.ReturnByPosition(0));
    // Assert
    QCOMPARE(model.GetPosition(), expected_position);
    QCOMPARE(model.GetPackageId(), expected_package_id);
    QCOMPARE(model.GetAction(), expected_action);
}

void SequenceOfPackageManagerTest::testConstructFromJson()
{
    // Arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"position", 0},
            {"package_id", 1},
            {"action", 0}
        };
    json_array.append(package1);
    json_obj["sequence_of_packages"] = json_array;

    // Expected values from JSON
    int expected_position = 0;
    int expected_package_id = 1;
    int expected_action = 0;

    // Act
    SequenceOfPackageManager manager(json_obj);
    SequenceOfPackageModel model(manager.ReturnByPosition(0));
    // Assert
    QCOMPARE(model.GetPosition(), expected_position);
    QCOMPARE(model.GetPackageId(), expected_package_id);
    QCOMPARE(model.GetAction(), expected_action);
}

void SequenceOfPackageManagerTest::testDumpToJson()
{
    //arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"position", 0},
            {"package_id", 1},
            {"action", 0}
        };
    json_array.append(package1);
    json_obj["sequence_of_packages"] = json_array;
    int act_pos = 0, act_pac_id = 1, act_act = 0;

    //act
    SequenceOfPackageManager manager(json_obj);
    QJsonObject test_json = manager.DumpToJson();
    int test_pos, test_pac_id, test_act;
    if(test_json.contains("sequence_of_packages"))
    {
        QJsonArray packages_array = test_json["sequence_of_packages"].toArray();
        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            if(buf_json.contains("position") && buf_json.contains("package_id") && buf_json.contains("action"))
            {
                test_pos = buf_json["position"].toInt();
                test_pac_id = buf_json["package_id"].toInt();
                test_act = buf_json["action"].toInt();
            }
        }
    }
    else
    {
        return;
    }
    //assert

    QCOMPARE(test_pos, act_pos);
    QCOMPARE(test_pac_id, act_pac_id);
    QCOMPARE(test_act, act_act);
}

void SequenceOfPackageManagerTest::testReturnByPos()
{

    //arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"position", 0},
            {"package_id", 1},
            {"action", 0}
        };
    json_array.append(package1);
    json_obj["sequence_of_packages"] = json_array;
    int act_pos = 0;

    //act
    SequenceOfPackageManager manager(json_obj);
    SequenceOfPackageModel model = manager.ReturnByPosition(0);

    //assert
    QCOMPARE(act_pos, model.GetPosition());
}

void SequenceOfPackageManagerTest::testReturnById()
{
    //arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"position", 0},
            {"package_id", 1},
            {"action", 0}
        };
    json_array.append(package1);
    json_obj["sequence_of_packages"] = json_array;
    int act_pack_id = 1;

    //act
    SequenceOfPackageManager manager(json_obj);
    QVector<SequenceOfPackageModel> vec = manager.ReturnByPackageId(1);

    //assert
    QCOMPARE(act_pack_id, vec[0].GetPackageId());
}


QTEST_APPLESS_MAIN(SequenceOfPackageManagerTest)

#include "SequenceOfPackageManagerTest.moc"

