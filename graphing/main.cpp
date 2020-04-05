#include <nodemanager.h>


#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include <QQmlProperty>
#include <QQmlContext>
#include <QtQml>

#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    NodeManager manager;

    auto rootContext = engine.rootContext();
    rootContext->setContextProperty("manager", &manager);

    rootContext->setContextProperty("node_model", &manager.node_model);
    rootContext->setContextProperty("arrow_model", &manager.arrow_model);

    //default properties
    rootContext->setContextProperty("nodeRadius", 8);
    rootContext->setContextProperty("wsHeight", 512);
    rootContext->setContextProperty("wsWidth", 512);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty()) return -1;

    return app.exec();
}
