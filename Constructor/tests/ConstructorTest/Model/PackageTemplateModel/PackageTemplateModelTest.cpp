#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/PackageTemplateModel/packagetemplatemodel.hpp"

class PackageTemplateModelTest : public QObject
{
    Q_OBJECT

public:
    PackageTemplateModelTest();
    ~PackageTemplateModelTest();
private slots:
    void testConstructor();
    void testGetSize_Description();
    void testAddSection();
    void testChangeSection();
    void testDeleteSection();
    void testDumpToJson();


};

PackageTemplateModelTest::PackageTemplateModelTest(){}
PackageTemplateModelTest::~PackageTemplateModelTest(){}

void PackageTemplateModelTest::testConstructor()
{
    //arrange
    QJsonObject json =
    {
        {"id", 0},
        {"size", 5}
    };
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonArray array_json;
    array_json.append(package1);
    json["sections"] = array_json;
    json["description"] = "abcd";
    json["name"] = "vania";
    int act_size = 5; QString description = "abcd";

    //act
    PackageTemplateModel model(json);

    //assert
    QCOMPARE(model.GetSize(), act_size);
    QCOMPARE(model.GetDescription(), description);
}

void PackageTemplateModelTest::testGetSize_Description()
{
    //arrange
    QJsonObject json =
        {
            {"id", 0},
            {"size", 5}
        };
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonArray array_json;
    array_json.append(package1);
    json["sections"] = array_json;
    json["description"] = "abcd";
    json["name"] = "vania";
    int act_size = 5; QString description = "abcd";

    //act
    PackageTemplateModel model(json);

    //assert
    QCOMPARE(model.GetSize(), act_size);
    QCOMPARE(model.GetDescription(), description);
}

void PackageTemplateModelTest::testDumpToJson()
{
    //arrange
    QJsonObject json =
        {
            {"id", 0},
            {"size", 5}
        };
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonArray array_json;
    array_json.append(package1);
    json["sections"] = array_json;
    json["description"] = "abcd";
    json["name"] = "vania";

    //act
    PackageTemplateModel model(json);
    QJsonObject res_json = model.DumpToJson();

    //assert
    QCOMPARE(res_json, json);
}

void PackageTemplateModelTest::testAddSection()
{
    //arrange
    QJsonObject json =
        {
            {"id", 0},
            {"size", 5}
        };
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonArray array_json;
    array_json.append(package1);
    json["sections"] = array_json;
    json["description"] = "abcd";
    json["name"] = "vania";

    QJsonObject package2 =
    {
        {"package_zone_id", 2},
        {"start_position", 3},
        {"size_section", 5}
    };

    //act
    PackageTemplateModel model(json);
    model.AddSection(1, package2);
    array_json.append(package2);
    json["sections"] = array_json;
    QJsonObject res_json = model.DumpToJson();

    //assert
    QCOMPARE(res_json, json);
}

void PackageTemplateModelTest::testChangeSection()
{
    //arrange
    QJsonObject json =
        {
            {"id", 0},
            {"size", 5}
        };
    QJsonObject package1 =
        {
            {"package_zone_id", 1},
            {"start_position", 1},
            {"size_section", 3}
        };
    QJsonArray array_json;
    array_json.append(package1);
    json["sections"] = array_json;
    json["description"] = "abcd";
    json["name"] = "vania";

    QJsonObject package2 =
        {
            {"package_zone_id", 2},
            {"start_position", 3},
            {"size_section", 5}
        };

    //act
}
