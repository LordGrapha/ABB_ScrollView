#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "abb.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ABB<QString>* test = new ABB<QString>();

    test->insert(10, "First One");
    test->insert(5, "Second One");
    test->insert(15, "Third One");
    test->insert(2, "Fourth One");
    test->insert(3, "Fifth One");
    test->insert(12, "Sixth One");
    test->insert(17, "Seventh One");
    test->inOrder();
    /*
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
    */
    return 0;
}