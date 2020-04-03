#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <nodemanager.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<NodeManager>("MyTools.NodeManager",1,0,"NodeManager");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) return -1;

    return app.exec();
}
