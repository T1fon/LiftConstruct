#include <functional>
#include <QtTest>
#include "../../../../src/Model/Logger/Logger.h"

// add necessary includes here

class LoggerTest : public QObject
{
    Q_OBJECT

public:
    LoggerTest();
    ~LoggerTest();
    void callback(Logger::log_error_t error,QString message);
private slots:
    void testInit();
    void testWriteMessage();
    void testInitOverflow();
    void testWriteMessageOverflow();
    void cleanupTestCase();
private:
    QDir __directory;

};

void LoggerTest::callback(Logger::log_error_t error,QString message)
{
    switch(error)
    {
    case Logger::FILE_OPEN:
        qDebug() << "Error: FILE_OPEN";
        break;
    }
    qDebug() << "Message: " << message;
}

LoggerTest::LoggerTest(){}

LoggerTest::~LoggerTest() {}

void LoggerTest::testInit()
{
    //arrage
    int count_file = 1;
    //act
    Logger::init(std::bind(&LoggerTest::callback,this, std::placeholders::_1,std::placeholders::_2));
    __directory = Logger::getDirectory();

    auto result = __directory.entryInfoList({"*.log"},QDir::Filter::Files,QDir::SortFlag::Time | QDir::SortFlag::Reversed);
    //assert
    QCOMPARE(result.size(),count_file);
}
void LoggerTest::testWriteMessage()
{
    //arrage
    QString data(1024*100,'a');
    int count_file = 1;
    //act
    Logger::writeMessage("LoggerTest","testWriteMessage",data,Logger::log_message_t::ERROR);
    auto result = __directory.entryInfoList({"*.log"},QDir::Filter::Files,QDir::SortFlag::Time | QDir::SortFlag::Reversed);
    //assert
    QCOMPARE(result.size(),count_file);
}
void LoggerTest::testInitOverflow()
{
    //arrage
    int count_file = 2;
    //act
    Logger::init(std::bind(&LoggerTest::callback,this, std::placeholders::_1,std::placeholders::_2));
    __directory = Logger::getDirectory();

    auto result = __directory.entryInfoList({"*.log"},QDir::Filter::Files,QDir::SortFlag::Time | QDir::SortFlag::Reversed);
    //assert
    QCOMPARE(result.size(),count_file);
}
void LoggerTest::testWriteMessageOverflow()
{
    //arrage
    QString data(1024*100,'a');
    int count_file = 3;
    //act
    Logger::writeMessage("LoggerTest","testWriteMessage",data,Logger::log_message_t::ERROR);
    Logger::writeMessage("LoggerTest","testWriteMessage",data,Logger::log_message_t::WARNING);
    auto result = __directory.entryInfoList({"*.log"},QDir::Filter::Files,QDir::SortFlag::Time | QDir::SortFlag::Reversed);
    //assert
    QCOMPARE(result.size(),count_file);
}

void LoggerTest::cleanupTestCase()
{
    Logger::clearDirectory();
}
QTEST_APPLESS_MAIN(LoggerTest)

#include "LoggerTest.moc"
