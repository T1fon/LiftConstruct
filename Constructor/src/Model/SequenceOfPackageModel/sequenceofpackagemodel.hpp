#ifndef SEQUENCEOFPACKAGEMODEL_HPP
#define SEQUENCEOFPACKAGEMODEL_HPP
#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDebug>

class SequenceOfPackageModel : public QObject
{
    Q_OBJECT
public:
    enum Action
    {
        SEND = 0,
        RECEIVE = 1
    };

    SequenceOfPackageModel(const QJsonObject& json);
    void SetPosition(int position);
    void SetPackageId(int package_id);
    void SetAction(int act);
    int GetPosition() const;
    int GetPackageId() const;
    int GetAction();
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson() const;
private:
    int __position;
    int __package_id;
    Action __action;
};

#endif // SEQUENCEOFPACKAGEMODEL_HPP
