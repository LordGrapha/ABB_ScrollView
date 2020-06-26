#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtCore>
#include "abb.h"

void searchTesting(ABB<QString>* test){
    qDebug() << "\n\nSearching 3";
    ABB_Node<QString>* tmp = test->search(3);
    if(tmp != nullptr){
        qDebug() << "Node found! And it is " << tmp->key << " the " << tmp->value;
    }
    else{
        qDebug() << "Node not found...";
    }
}


void insertTesting(ABB<QString>* test){
    test->insert(10, "First One");
    test->insert(5, "Second One");
    test->insert(15, "Third One");
    test->insert(2, "Fourth One");
    test->insert(3, "Fifth One");
    test->insert(12, "Sixth One");
    test->insert(17, "Seventh One");
}

void updateTesting(ABB<QString>* test){
    test->update(3, "The THIRD Choosen one");
}

void deleteTesting(ABB<QString>* test){
    test->remove(3);
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    ABB<QString>* test = new ABB<QString>();

    insertTesting(test);
    test->inOrder();
    searchTesting(test);
    updateTesting(test);
    searchTesting(test);
    //deleteTesting(test);      Finish the function first


    /*
     * Next Actions: Update and delete features
     * Test all the cases.
     *
     ******************   UML Diagram URGENT    **************************
     */

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
