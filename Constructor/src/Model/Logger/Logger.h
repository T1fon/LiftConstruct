#ifndef LOGGER_H
#define LOGGER_H
#include <QObject>
#include <QDir>
#include <QFile>
#include <QTextStream>

class Logger
{
public:
    enum log_message_t
    {
        ERROR = 0,
        WARNING,
        EVENT
    };
    enum log_error_t
    {
        FILE_OPEN = 1
    };
    static const QString DEFAULT_PATH;
    static const QString DEFAULT_DIRECTORY;
    static const QString DEFAULT_FILE_PREFIX;
    static const size_t DEFAULT_MAX_FILESIZE;

    typedef std::function<void(log_error_t,QString)> error_func_t;

    Logger();
    static void init(error_func_t callback = {}, QString path = DEFAULT_PATH, QString directory = DEFAULT_DIRECTORY,
                     QString file_prefix = DEFAULT_FILE_PREFIX, size_t max_filesize = DEFAULT_MAX_FILESIZE);
    static void writeMessage(QString class_name, QString method_name, QString message, log_message_t log_type);
    static QDir getDirectory();
    static void clearDirectory();
private:
    static size_t __max_filesize;
    static const QString __DEFAULT_FILE_POSTFIX;
    static const uint16_t __DEFAULT_DELTA_FILESIZE;
    static QDir __directory;
    static QFile __log_file;
    static QTextStream __fout;
    static error_func_t __callback;
    static QString __file_prefix;
};

#endif // LOGGER_H
