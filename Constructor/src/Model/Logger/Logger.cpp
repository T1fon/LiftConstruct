#include "Logger.h"

const QString Logger::DEFAULT_PATH = "./";
const QString Logger::DEFAULT_DIRECTORY = "Log";
const QString Logger::DEFAULT_FILE_PREFIX = "log";
const QString Logger::__DEFAULT_FILE_POSTFIX = ".log";
QDir Logger::__directory = QDir(DEFAULT_PATH + DEFAULT_DIRECTORY);
QFile Logger::__log_file = QFile(DEFAULT_FILE_PREFIX + QDate::currentDate().toString("dd_MM_yy_hh_mm_ss_zzz") + __DEFAULT_FILE_POSTFIX);
QTextStream Logger::__fout(&__log_file);
const size_t Logger::DEFAULT_MAX_FILESIZE = 1024*100; //100Kb
const uint16_t Logger::__DEFAULT_DELTA_FILESIZE = 1024*2;
size_t Logger::__max_filesize = DEFAULT_MAX_FILESIZE;
QString Logger::__file_prefix = Logger::DEFAULT_FILE_PREFIX;
Logger::error_func_t Logger::__callback = {};

Logger::Logger(){}

void Logger::init(error_func_t callback, QString path, QString directory, QString file_prefix, size_t max_filesize)
{
    __callback = callback;
    __file_prefix = file_prefix;
    if(max_filesize < __DEFAULT_DELTA_FILESIZE)
    {
        max_filesize = DEFAULT_MAX_FILESIZE;
    }
    __max_filesize = max_filesize;

    __directory.setPath(path+directory);
    qDebug() << __directory.absolutePath();
    if(!__directory.exists()){
        __directory.mkpath(path);
    }
    QString log_file_path_name = __file_prefix + "_" +QDate::currentDate().toString("dd_MM_yy") + __DEFAULT_FILE_POSTFIX;

    auto res = __directory.entryInfoList({"*" + __DEFAULT_FILE_POSTFIX},QDir::Filter::Files,QDir::SortFlag::Time | QDir::SortFlag::Reversed);
    if(res.size() > 0){
        QFileInfo searching_file = res.first();
        if(searching_file.birthTime().date() == QDate::currentDate())
        {
            qDebug() <<"size"<< searching_file.size();
            if(searching_file.size() < (__max_filesize - __DEFAULT_DELTA_FILESIZE))
            {
                log_file_path_name = searching_file.fileName();
            }else{
                log_file_path_name = __file_prefix + "_" + QDateTime::currentDateTime().toString("dd_MM_yy_hh_mm_ss_zzz") + __DEFAULT_FILE_POSTFIX;
            }
        }
    }

    __log_file.setFileName(__directory.absolutePath() +"/"+ log_file_path_name);
    if(!__log_file.open(QFile::WriteOnly))
    {
        try{
            __callback(log_error_t::FILE_OPEN, "Class: Logger; method: init; message: Error open log file. Filename: " + __log_file.fileName());
        }catch(std::bad_function_call &e){
            qDebug() << "Class: Logger; method: init; error: " << e.what();
        }

        return;
    }
    __log_file.close();
}
void Logger::writeMessage(QString class_name, QString method_name, QString message, log_message_t log_type)
{
    qDebug() << __log_file.size();
    if(__log_file.size() > (__max_filesize - __DEFAULT_DELTA_FILESIZE))
    {
        QString current_filename = __directory.absolutePath() + "/" + __file_prefix + "_" + QDateTime::currentDateTime().toString("dd_MM_yy_hh_mm_ss_zzz") + __DEFAULT_FILE_POSTFIX;
        __log_file.setFileName(current_filename);
    }
    if(!__log_file.open(QFile::WriteOnly))
    {
        try{
            __callback(log_error_t::FILE_OPEN, "Class: Logger; method: writeMessage; message: Error open log file. Filename: " + __log_file.fileName());
        }catch(std::bad_function_call &e){
            qDebug() << "Class: Logger; method: writeMessage; error: " << e.what();
        }
        return;
    }

    QString log_type_value;

    switch(log_type)
    {
    case ERROR:
        log_type_value = "error";
        break;
    case WARNING:
        log_type_value = "warning";
        break;
    case EVENT:
        log_type_value = "event";
        break;
    default:
        log_type_value = "unknown";
        break;
    }

    __fout <<"[" << QDateTime::currentDateTime().toString() << "][" << log_type_value << "] "
           << "Class:" << class_name << "; method: " << method_name << "; message: " << message << "\n";
    __fout.flush();

    __log_file.close();
}
QDir Logger::getDirectory()
{
    return __directory;
}
void Logger::clearDirectory()
{
    __directory.removeRecursively();
}
