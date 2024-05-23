#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Controller/MainManager/mainmanager.hpp"
#include "Controller/ProjectManager/projectmanager.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<ProjectManager>("ProjectManager", 1, 0, "ProjectManager");
    qmlRegisterType<MainManager>("MainManager", 1, 0, "MainManager");


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Constructor/src/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
