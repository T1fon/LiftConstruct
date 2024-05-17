#include <QJsonObject>
#include <QtTest>
#include <QColor>
#include "../../../../src/Model/ZonePackageModel/zonepackagemodel.hpp"

class ZonePackageModelTest : public QObject
{
    Q_OBJECT
public:
    ZonePackageModelTest();
    ~ZonePackageModelTest();
private slots:
    void testConstructor1();
    void testConstructor2();
    void testConstructor3();
    void testConstructor4();
    void testConstructor5();
    void testGettersSetters();
    void testDumpToJson();
};

ZonePackageModelTest::ZonePackageModelTest(){}
ZonePackageModelTest::~ZonePackageModelTest(){}

void ZonePackageModelTest::testConstructor1()
{
    //arrange
    QColor color = "";
    QString name = "";

    //act
    ZonePackageModel model;
    //assert
    QCOMPARE(model.name(), name);
    QCOMPARE(model.color(), color);
}

void ZonePackageModelTest::testConstructor2()
{
    //arrange
    QColor color = "";
    QString name = "";

    //act
    ZonePackageModel model;
    ZonePackageModel model1(model);
    //assert
    QCOMPARE(model1.name(), name);
    QCOMPARE(model1.color(), color);
}

void ZonePackageModelTest::testConstructor3()
{
    //arrange
    QColor color = "";
    QString name = "";
    size_t id = 2;

    //act
    ZonePackageModel model(id, name, color);
    //assert
    QCOMPARE(model.id(), id);
    QCOMPARE(model.name(), name);
    QCOMPARE(model.color(), color);
}

void ZonePackageModelTest::testConstructor4()
{
    //arrange
    QColor color = "";
    QString name = "";

    //act
    ZonePackageModel model(name, color);
    //assert
    QCOMPARE(model.name(), name);
    QCOMPARE(model.color(), color);
}

void ZonePackageModelTest::testConstructor5()
{
    //arrange

    QJsonObject json =
    {
        {"id", 1},
        {"name", ""},
        {"color",""}
    };

    QColor color = "";
    QString name = "";
    size_t id = 1;

    //act
    ZonePackageModel model(json);
    //assert
    QCOMPARE(model.id(), id);
    QCOMPARE(model.name(), name);
    QCOMPARE(model.color(), color);
}

void ZonePackageModelTest::testGettersSetters()
{
    //arrange
    QString name = "ffff";
    QColor color = "";

    //act
    ZonePackageModel model;
    model.setColor(color);
    model.setName(name);

    //assert
    QCOMPARE(model.color(), color);
    QCOMPARE(model.name(), name);
}
void ZonePackageModelTest::testDumpToJson()
{
    //arrange
    QJsonObject json =
        {
            {"id", 0},
            {"name", "abcd"},
            {"color",""}
        };

    //act
    ZonePackageModel model(json);
    QJsonObject res_json = model.toJsonObject();
    //assert
    QCOMPARE(res_json["id"].toInt(), json["id"].toInt());
    QCOMPARE(res_json["name"].toInt(), json["name"].toInt());
    QCOMPARE(res_json["color"].toInt(), json["color"].toInt());
}

QTEST_APPLESS_MAIN(ZonePackageModelTest)

#include "ZonePackageModelTest.moc"
