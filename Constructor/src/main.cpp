#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "View/PackageZoneMenu/PackageZoneView.h"
#include "View/ConstructMenu/constructview.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<PackageZoneView>("Package_Zone_View", 1, 0, "Package_Zone_View");
    qmlRegisterType<ConstructView>("Construct_View", 1, 0, "Construct_View");

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
