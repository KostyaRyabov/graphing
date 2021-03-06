#include <nodemanager.h>


#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include <QQmlProperty>
#include <QQmlContext>
#include <QtQml>

#include <QVariant>

#include <options.h>

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
    rootContext->setContextProperty("nodeRadius", Node_Radius);
    rootContext->setContextProperty("SelectorRadius", Selector_Radius);
    rootContext->setContextProperty("wsHeight", ws_Height);
    rootContext->setContextProperty("wsWidth", ws_Width);

    rootContext->setContextProperty("delayCD", delayCD);
    rootContext->setContextProperty("changeTime", changeTime);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //QObject::connect(&manager, SIGNAL(debug(QString)), obj, SLOT(message(QString)));


    if (engine.rootObjects().isEmpty()) return -1;

    return app.exec();
}
