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

    NodeManager manager;

    return app.exec();
}
