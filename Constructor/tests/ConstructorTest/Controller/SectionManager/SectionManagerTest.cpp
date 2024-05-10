#include<QJsonObject>
#include <QJsonArray>
#include <QtTest>
#include "../../../../src/Controller/SectionManager/sectionmanager.hpp"
#include"../../../../src/Model/SectionModel/sectionmodel.hpp"

class SectionManagerTest : public QObject
{
    Q_OBJECT
public:
    SectionManagerTest();
    ~SectionManagerTest();
private slots:
    void testConstructor();
    void testTotalSize();
    void testAddSection();
    void testChangeSection();
    void testDeleteSection();
    void testSearchSection();
    void testGetSections();
    void testDumpToJson();
};

SectionManagerTest::SectionManagerTest(){}
SectionManagerTest::~SectionManagerTest(){}

void SectionManagerTest::testConstructor()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_obj["sections"] = json_array;
    int act_pack_id = 1, act_pos = 1, act_size = 3;

    //act
    SectionManager manager(json_obj);
    QVector<SectionModel> vec = manager.GetSections();

    //assert
    QCOMPARE(vec[0].GetPackageZoneId(), act_pack_id);
    QCOMPARE(vec[0].GetStartPosition(), act_pos);
    QCOMPARE(vec[0].GetSizeStation(), act_size);
}

void SectionManagerTest::testTotalSize()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
    {
        {"package_zone_id", 1},
        {"start_position", 1},
        {"size_section", 3}
    };
    QJsonObject package2 =
    {
        {"package_zone_id", 2},
        {"start_position", 1},
        {"size_section", 3}
    };
    json_array.append(package1);
    json_array.append(package2);
    json_obj["sections"] = json_array;
    int act_size = 2;

    //act
    SectionManager manager(json_obj);

    //assert
    QCOMPARE(manager.GetTotalSize(), act_size);
}

void SectionManagerTest::testAddSection()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonObject package2 =
        {
            {"package_zone_id", 2},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_obj["sections"] = json_array;
    int act_size = 2;

    //act
    SectionManager manager(json_obj);
    manager.AddSection(0, package2);

    //assert
    QCOMPARE(manager.GetTotalSize(), act_size);
}

void SectionManagerTest::testChangeSection()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_obj["sections"] = json_array;
    int act_pac =2, act_pos = 2, act_size = 4;

    //act
    SectionManager manager(json_obj);
    manager.ChangeSection(0, 2, 2, 4);

    //assert
    QVector<SectionModel> vec = manager.GetSections();

    //assert
    QCOMPARE(vec[0].GetPackageZoneId(), act_pac);
    QCOMPARE(vec[0].GetStartPosition(), act_pos);
    QCOMPARE(vec[0].GetSizeStation(), act_size);

}

void SectionManagerTest::testDeleteSection()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonObject package2 =
        {
            {"package_zone_id", 2},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_array.append(package2);
    json_obj["sections"] = json_array;
    int act_size = 1;

    //act
    SectionManager manager(json_obj);
    manager.DeleteSection(1);

    //assert
    QCOMPARE(manager.GetTotalSize(), act_size);
}

void SectionManagerTest::testGetSections()
{
    //arrange

    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_obj["sections"] = json_array;
    int act_pack_id = 1, act_pos = 1, act_size = 3;

    //act
    SectionManager manager(json_obj);
    QVector<SectionModel> vec = manager.GetSections();

    //assert
    QCOMPARE(vec[0].GetPackageZoneId(), act_pack_id);
    QCOMPARE(vec[0].GetStartPosition(), act_pos);
    QCOMPARE(vec[0].GetSizeStation(), act_size);
}

void SectionManagerTest::testDumpToJson()
{
    //arrange
    QJsonObject json_obj;
    QJsonArray json_array;
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    json_array.append(package1);
    json_obj["sections"] = json_array;
    int act_pack_id = 1, act_pos = 1, act_size = 3;

    //act
    SectionManager manager(json_obj);
    QJsonObject test_json = manager.DumpToJson();
    int test_pac, test_pos, test_size;
    if(test_json.contains("sections"))
    {
        QJsonArray packages_array = test_json["sections"].toArray();
        for(const auto& item : packages_array)
        {
            const QJsonObject buf_json = item.toObject();
            if(buf_json.contains("package_zone_id") && buf_json.contains("start_position") && buf_json.contains("size_section"))
            {
                test_pac = buf_json["package_zone_id"].toInt();
                test_pos = buf_json["start_position"].toInt();
                test_size = buf_json["size_section"].toInt();
            }
        }
    }
    else
    {
        return;
    }

    //assert
    QCOMPARE(test_pac, act_pack_id);
    QCOMPARE(test_pos, act_pos);
    QCOMPARE(test_size, act_size);
}

QTEST_APPLESS_MAIN(SectionManagerTest)

#include "SectionManagerTest.moc"
