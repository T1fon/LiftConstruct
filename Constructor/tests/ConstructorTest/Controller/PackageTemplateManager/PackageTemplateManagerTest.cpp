#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Controller/PackageTemplateManager/packagetemplatemanager.hpp"

class PackageTemplateManagerTest : public QObject
{
    Q_OBJECT
public:
    PackageTemplateManagerTest();
    ~PackageTemplateManagerTest();
private slots:
    void testConstruct();
    void testDumpToJson();
    void testChangeElement1();
    void testChangeElement2();
    void testChangeElement3();
    void testChangeElement4();
    void testDeleteElement1();
    void testDeleteElement2();
    void testGetSize();
    void testGetModel();
};

PackageTemplateManagerTest::PackageTemplateManagerTest(){}
PackageTemplateManagerTest::~PackageTemplateManagerTest(){}

void PackageTemplateManagerTest::testConstruct()
{
    //arrange
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    PackageTemplateModel model = manager.getModel(5);

    //assert

    QCOMPARE(model.getId(), json["id"].toInt());
    QCOMPARE(model.GetDescription(), json["description"].toString());
    QCOMPARE(model.GetSize(), json["size"].toInt());
    QCOMPARE(model.GetName(), json["name"].toString());

}
void PackageTemplateManagerTest::testDumpToJson()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["package_zone_id"] = 3;
    section["start_position"] = 4;
    section["size_section"] = 2;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    QJsonArray res_array = manager.DumpToJson();
    QJsonObject res_json;
    res_json["package_template"] = res_array;

    //assert

    QCOMPARE(res_json, test_json);


}
void PackageTemplateManagerTest::testChangeElement1()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.ChangeElement("Test 1", 15, "goodbye");
    PackageTemplateModel model = manager.getModel(5);

    //assert
    QCOMPARE(model.GetDescription(), "goodbye");
    QCOMPARE(model.GetSize(), 15);
    QCOMPARE(model.GetName(), "Test 1");
}
void PackageTemplateManagerTest::testChangeElement2()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.ChangeElement(5, "Test 2", 20, "good");
    PackageTemplateModel model = manager.getModel(5);

    //assert
    QCOMPARE(model.GetDescription(), "good");
    QCOMPARE(model.GetSize(), 20);
    QCOMPARE(model.GetName(), "Test 2");
}
void PackageTemplateManagerTest::testChangeElement3()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.ChangeElement("Test 1", 0, 7, 5, 3);
    PackageTemplateModel model = manager.getModel(5);
    SectionManager sect_manager = model.getSection();
    SectionModel sect_model = sect_manager.getModel(0);

    //assert
    QCOMPARE(sect_model.GetPackageZoneId(), 7);
    QCOMPARE(sect_model.GetStartPosition(), 5);
    QCOMPARE(sect_model.GetSizeStation(), 3);

}
void PackageTemplateManagerTest::testChangeElement4()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.ChangeElement(5, 0, 7, 5, 3);
    PackageTemplateModel model = manager.getModel(5);
    SectionManager sect_manager = model.getSection();
    SectionModel sect_model = sect_manager.getModel(0);

    //assert
    QCOMPARE(sect_model.GetPackageZoneId(), 7);
    QCOMPARE(sect_model.GetStartPosition(), 5);
    QCOMPARE(sect_model.GetSizeStation(), 3);

}
void PackageTemplateManagerTest::testDeleteElement1()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    QJsonObject json2;
    json2["id"] = 4;
    json2["size"] = 10;
    QJsonArray sections1;
    QJsonObject section1;
    section1["add_queue"] = 3;
    section1["package_zone_id"] = 7;
    section1["start_position"] = 4;
    section1["size_section"] = 1;
    sections1.append(section1);
    json2["sections"] = sections1;
    json2["description"] = "hellow";
    json2["name"] = "Test 2";

    test_massive.append(json);
    test_massive.append(json2);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.DeleteElement(4);

    QCOMPARE(manager.getSize(), 1);
}

void PackageTemplateManagerTest::testDeleteElement2()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    QJsonObject json2;
    json2["id"] = 4;
    json2["size"] = 10;
    QJsonArray sections1;
    QJsonObject section1;
    section1["add_queue"] = 3;
    section1["package_zone_id"] = 7;
    section1["start_position"] = 4;
    section1["size_section"] = 1;
    sections1.append(section1);
    json2["sections"] = sections1;
    json2["description"] = "hellow";
    json2["name"] = "Test 2";

    test_massive.append(json);
    test_massive.append(json2);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.DeleteElement("Test 1");

    QCOMPARE(manager.getSize(), 1);
}
void PackageTemplateManagerTest::testGetSize()
{
    //arrange
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);

    //assert

    QCOMPARE(manager.getSize(), 1);

}
void PackageTemplateManagerTest::testGetModel()
{
    QJsonArray test_massive;

    QJsonObject json;
    json["id"] = 5;
    json["size"] = 10;
    QJsonArray sections;
    QJsonObject section;
    section["add_queue"] = 0;
    section["package_zone_id"] = 0;
    section["start_position"] = 0;
    section["size_section"] = 1;
    sections.append(section);
    json["sections"] = sections;
    json["description"] = "hellow";
    json["name"] = "Test 1";

    test_massive.append(json);
    QJsonObject test_json;
    test_json["package_template"] = test_massive;

    //act
    PackageTemplateManager manager(test_json);
    manager.ChangeElement(5, "Test 2", 20, "good");
    PackageTemplateModel model = manager.getModel(5);

    //assert
    QCOMPARE(model.GetDescription(), "good");
    QCOMPARE(model.GetSize(), 20);
    QCOMPARE(model.GetName(), "Test 2");
}
QTEST_APPLESS_MAIN(PackageTemplateManagerTest)

#include "PackageTemplateManagerTest.moc"
