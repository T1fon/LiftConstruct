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
    SequenceOfPackageModel(const size_t& position, const size_t& package_id, const size_t& action);
    SequenceOfPackageModel(const SequenceOfPackageModel& other);
    SequenceOfPackageModel& operator=(const SequenceOfPackageModel& other)
    {
        if (this != &other)
        {
            __position = other.__position;
            __package_id = other.__package_id;
            __action = other.__action;
        }
        return *this;
    }
    bool operator<(const SequenceOfPackageModel& other) const
    {
        // Define your comparison logic here
        if (__position < other.__position)
        {
            return true;
        }
        else if (__position == other.__position)
        {
            if (__package_id < other.__package_id)
            {
                return true;
            }
            else if (__package_id == other.__package_id)
            {
                return __action < other.__action;
            }
        }
        return false;
    }
    void SetPosition(const size_t& position);
    void SetPackageId(const size_t& package_id);
    void SetAction(const size_t& act);
    size_t GetPosition() const;
    size_t GetPackageId() const;
    size_t GetAction() const;
    void ConstructFromJson(const QJsonObject& json);
    QJsonObject DumpToJson() const;
private:
    size_t __position;
    size_t __package_id;
    Action __action;
};

#endif // SEQUENCEOFPACKAGEMODEL_HPP
