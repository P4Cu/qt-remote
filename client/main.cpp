#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "rep_simpleswitch_replica.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // This is where replica gest registered to QML
    qmlRegisterType<SimpleSwitchReplica>("custom", 1, 0, "SimpleSwitchReplica");

    // default implementation
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
