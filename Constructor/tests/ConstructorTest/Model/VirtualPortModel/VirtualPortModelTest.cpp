#include<QJsonObject>
#include<QtTest>
#include <QtSerialPort/QSerialPort>
#include "../../../../src/Model/VirtualPortModel/virtualportmodel.hpp"

class VirtualPortModeLTest : public QObject
{
    Q_OBJECT
public:
    VirtualPortModeLTest();
    ~VirtualPortModeLTest();
public slots:
    void testConstructor1();
    void testConstructor2();
    void testConstructor3();
    void testGettersSetters();
    void testConstructFromJson();
    void testDumpToJson();
};

VirtualPortModeLTest::VirtualPortModeLTest(){}
VirtualPortModeLTest::~VirtualPortModeLTest(){}

void VirtualPortModeLTest::testConstructor1()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;

    //act
    VirtualPortModel model(physical_interface, bod, bit_of_data, parity, stop_bits, flow_control);
    QString test_physical_interface = model.GetPhysicalInterface();
    int32_t test_bod = model.GetBod();
    QSerialPort::DataBits test_bit_of_data = model.GetBitOfData();
    QSerialPort::Parity test_parity = model.GetParity();
    QSerialPort::StopBits test_stop_bits = model.GetStopBits();
    QSerialPort::FlowControl test_flow_control = model.GetFlowControl();

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}

void VirtualPortModeLTest::testConstructor2()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;

    //act
    VirtualPortModel a(physical_interface, bod, bit_of_data, parity, stop_bits, flow_control);
    VirtualPortModel model(a);
    QString test_physical_interface = model.GetPhysicalInterface();
    int32_t test_bod = model.GetBod();
    QSerialPort::DataBits test_bit_of_data = model.GetBitOfData();
    QSerialPort::Parity test_parity = model.GetParity();
    QSerialPort::StopBits test_stop_bits = model.GetStopBits();
    QSerialPort::FlowControl test_flow_control = model.GetFlowControl();

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}

void VirtualPortModeLTest::testConstructor3()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;
    QJsonObject json =
    {
        {"physical_interface", "abcd"},
        {"bod", 5},
        {"bit_of_data", "Data8"},
        {"parity", "NoParity"},
        {"stop_bits", "OneStop"},
        {"flow_control", "NoFlowControl"}
    };
    VirtualPortModel model(json);
    QString test_physical_interface = model.GetPhysicalInterface();
    int32_t test_bod = model.GetBod();
    QSerialPort::DataBits test_bit_of_data = model.GetBitOfData();
    QSerialPort::Parity test_parity = model.GetParity();
    QSerialPort::StopBits test_stop_bits = model.GetStopBits();
    QSerialPort::FlowControl test_flow_control = model.GetFlowControl();

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}

void VirtualPortModeLTest::testConstructFromJson()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;
    QJsonObject json =
        {
            {"physical_interface", "abcd"},
            {"bod", 5},
            {"bit_of_data", "Data8"},
            {"parity", "NoParity"},
            {"stop_bits", "OneStop"},
            {"flow_control", "NoFlowControl"}
        };
    VirtualPortModel model("", 0, bit_of_data, parity, stop_bits, flow_control);
    model.ConstructFromJson(json);
    QString test_physical_interface = model.GetPhysicalInterface();
    int32_t test_bod = model.GetBod();
    QSerialPort::DataBits test_bit_of_data = model.GetBitOfData();
    QSerialPort::Parity test_parity = model.GetParity();
    QSerialPort::StopBits test_stop_bits = model.GetStopBits();
    QSerialPort::FlowControl test_flow_control = model.GetFlowControl();

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}

void VirtualPortModeLTest::testGettersSetters()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;

    //act
    VirtualPortModel model("", 0, QSerialPort::Data5, QSerialPort::OddParity, QSerialPort::TwoStop, QSerialPort::SoftwareControl);
    model.SetFlowControl(flow_control);
    model.SetParity(parity);
    model.SetBitOfData(bit_of_data);
    model.SetBod(bod);
    model.SetPhysicalInterface(physical_interface);
    model.SetStopBits(stop_bits);
    QString test_physical_interface = model.GetPhysicalInterface();
    int32_t test_bod = model.GetBod();
    QSerialPort::DataBits test_bit_of_data = model.GetBitOfData();
    QSerialPort::Parity test_parity = model.GetParity();
    QSerialPort::StopBits test_stop_bits = model.GetStopBits();
    QSerialPort::FlowControl test_flow_control = model.GetFlowControl();

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}

void VirtualPortModeLTest::testDumpToJson()
{
    //arrange
    QString physical_interface = "abcd";
    int32_t bod = 5;
    QSerialPort::DataBits bit_of_data = QSerialPort::Data8;
    QSerialPort::Parity parity = QSerialPort::NoParity;
    QSerialPort::StopBits stop_bits = QSerialPort::OneStop;
    QSerialPort::FlowControl flow_control = QSerialPort::NoFlowControl;

    //act
    VirtualPortModel model(physical_interface, bod, bit_of_data, parity, stop_bits, flow_control);
    QJsonObject json = model.toJson();
    QString test_physical_interface = json["physical_interface"].toString();
    int32_t test_bod = json["bod"].toInt();
    QSerialPort::DataBits test_bit_of_data = static_cast<QSerialPort::DataBits>(json["bit_of_data"].toInt());
    QSerialPort::Parity test_parity = static_cast<QSerialPort::Parity>(json["parity"].toInt());
    QSerialPort::StopBits test_stop_bits = static_cast<QSerialPort::StopBits>(json["stop_bits"].toInt());
    QSerialPort::FlowControl test_flow_control = static_cast<QSerialPort::FlowControl>(json["flow_control"].toInt());

    //assert
    QCOMPARE(physical_interface, test_physical_interface);
    QCOMPARE(bod, test_bod);
    QCOMPARE(bit_of_data, test_bit_of_data);
    QCOMPARE(parity, test_parity);
    QCOMPARE(stop_bits, test_stop_bits);
    QCOMPARE(flow_control, test_flow_control);
}
