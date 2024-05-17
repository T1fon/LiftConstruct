#include<QJsonObject>
#include <QtTest>
#include "../../../../src/Model/PackageModel/packagemodel.hpp"

class PackageModelTest : public QObject
{
    Q_OBJECT
public:
    PackageModelTest();
    ~PackageModelTest();
private slots:
    void testConstruct1();
    void testConstruct2();
    void testSettersGetters();
    void testDumpToJson();
    void testSetterBytes();
};

PackageModelTest::PackageModelTest(){}
PackageModelTest::~PackageModelTest(){}

void PackageModelTest::testConstruct1()
{
    //arrange
    QJsonObject json =
    {
        {"id", 1},
        {"station_id", 4},
        {"package_template_id", 7},
        {"name", "test1"},
        {"data", "01010101"},
        {"description", "test1 lala"}
    };
    QVector<uint8_t> vect = {0, 1, 0, 1, 0, 1, 0, 1};
    //act
    PackageModel model(json);

    //assert
    QCOMPARE(model.GetId(), json["id"].toInt());
    QCOMPARE(model.GetStationId(), json["station_id"].toInt());
    QCOMPARE(model.GetPackageTemplateId(), json["package_template_id"].toInt());
    QCOMPARE(model.GetName(), json["name"].toString());
    QVector<uint8_t> res_vect = model.GetData();
    for(size_t i = 0; i < vect.size(); i++)
    {
        qDebug() << vect[i] << " " << res_vect[i];
    }
    QCOMPARE(model.GetData(), vect);
    QCOMPARE(model.GetDescription(), json["description"].toString());
}

void PackageModelTest::testConstruct2()
{
    //arrange
    size_t station_id = 5;
    size_t package_template_id = 7;
    QString name = "name";
    QVector<uint8_t> vect = {0, 1, 0, 1, 0, 1, 0, 1};
    QString description = "description";

    //act

    PackageModel model(station_id, package_template_id, name, vect, description);


    //assert
    QCOMPARE(model.GetStationId(), station_id);
    QCOMPARE(model.GetPackageTemplateId(), package_template_id);
    QCOMPARE(model.GetName(), name);
    QCOMPARE(model.GetData(), vect);
    QCOMPARE(model.GetDescription(), description);
}

void PackageModelTest::testSettersGetters()
{
    //arrange
    size_t station_id = 0;
    size_t package_template_id = 0;
    QString name = "";
    QVector<uint8_t> vect = {0, 0, 0, 0, 0, 0, 0, 0};
    QString description = "";

    size_t res_station_id = 5;
    size_t res_package_template_id = 7;
    QString res_name = "name";
    QVector<uint8_t> res_vect = {0, 1, 0, 0, 1, 0, 0, 1};
    QString res_description = "description";
    //act

    PackageModel model(station_id, package_template_id, name, vect, description);
    model.SetStationId(5);
    model.SetPackageTamplateId(7);
    model.SetName("name");
    model.SetData(res_vect);
    model.SetDescription("description");

    //assert
    QCOMPARE(model.GetStationId(), res_station_id);
    QCOMPARE(model.GetPackageTemplateId(), res_package_template_id);
    QCOMPARE(model.GetName(), res_name);
    QCOMPARE(model.GetData(), res_vect);
    QCOMPARE(model.GetDescription(), res_description);
}

void PackageModelTest::testDumpToJson()
{
    //arrange
    QJsonObject json =
        {
            {"id", 1},
            {"station_id", 4},
            {"package_template_id", 7},
            {"name", "test1"},
            {"data", "01010101"},
            {"description", "test1 lala"}
        };

    //act
    PackageModel model(json);

    QJsonObject res_json = model.DumpToJson();

    //assert
    QCOMPARE(res_json["id"].toInt(), json["id"].toInt());
    QCOMPARE(res_json["station_id"].toInt(), json["station_id"].toInt());
    QCOMPARE(res_json["package_template_id"].toInt(), json["package_template_id"].toInt());
    QCOMPARE(res_json["name"].toString(), json["name"].toString());
    QCOMPARE(res_json["data"].toString(), json["data"].toString());
    QCOMPARE(res_json["description"].toString(), json["description"].toString());
}

void PackageModelTest::testSetterBytes()
{
    //arrange

    size_t station_id = 0;
    size_t package_template_id = 0;
    QString name = "";
    QVector<uint8_t> vect = {0, 0, 0, 0, 0, 0, 0, 0};
    QString description = "";
    QVector<uint8_t> res_vect = {1, 0, 1, 0, 1, 0, 0, 0};

    //act

    PackageModel model(station_id, package_template_id, name, vect, description);
    model.SetByte(0, 1);
    model.SetByte(2, 1);
    model.SetByte(4, 1);

    //assert
    QCOMPARE(model.GetData(), res_vect);
}

QTEST_APPLESS_MAIN(PackageModelTest)

#include "PackageModelTest.moc"
