#ifndef VIRTUALPORTMODEL_HPP
#define VIRTUALPORTMODEL_HPP

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>
#include <QtSerialPort/QSerialPort>


class VirtualPortModel
{
public:
    VirtualPortModel(QString physical_interface, int32_t bod, QSerialPort::DataBits bit_of_data, QSerialPort::Parity parity,
            QSerialPort::StopBits stop_bits, QSerialPort::FlowControl flow_control);
    VirtualPortModel(const VirtualPortModel& other);
    VirtualPortModel(const QJsonObject& json);
    void SetPhysicalInterface(const QString& physical_interface);
    void SetBod(const int32_t& bod);
    void SetBitOfData(const QSerialPort::DataBits& bit_of_data);
    void SetParity(const QSerialPort::Parity& parity);
    void SetStopBits(const QSerialPort::StopBits& stop_bits);
    void SetFlowControl(QSerialPort::FlowControl& flow_control);
    QString GetPhysicalInterface() const;
    int32_t GetBod() const;
    QSerialPort::DataBits GetBitOfData() const;
    QSerialPort::Parity GetParity() const;
    QSerialPort::StopBits GetStopBits() const;
    QSerialPort::FlowControl GetFlowControl() const;
    QJsonObject toJson();
private:
    QString __physical_interface;
    int32_t __bod;
    QSerialPort::DataBits __bit_of_data;
    QSerialPort::Parity __parity;
    QSerialPort::StopBits __stop_bits;
    QSerialPort::FlowControl __flow_control;
    void __ErrorMsg(QString object);

};

#endif // VIRTUALPORTMODEL_HPP
