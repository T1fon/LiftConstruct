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
    VirtualPortModel(const QString& physical_interface, const int32_t& bod, const QSerialPort::DataBits& bit_of_data,
                     const QSerialPort::Parity& parity, const QSerialPort::StopBits& stop_bits,
                     const QSerialPort::FlowControl& flow_control);
    VirtualPortModel(const VirtualPortModel& other);
    VirtualPortModel(const QJsonObject& json);
    VirtualPortModel();
    void setPhysicalInterface(const QString& physical_interface);
    void setBod(const int32_t& bod);
    void setBitOfData(const QSerialPort::DataBits& bit_of_data);
    void setParity(const QSerialPort::Parity& parity);
    void setStopBits(const QSerialPort::StopBits& stop_bits);
    void setFlowControl(const QSerialPort::FlowControl& flow_control);
    QString getPhysicalInterface() const;
    int32_t getBod() const;
    QSerialPort::DataBits getBitOfData() const;
    QSerialPort::Parity getParity() const;
    QSerialPort::StopBits getStopBits() const;
    QSerialPort::FlowControl getFlowControl() const;
    QJsonObject toJson();
    void constructFromJson(const QJsonObject& json);
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
