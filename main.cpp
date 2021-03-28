#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "plateau.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    Plateau aPlateau;
    aPlateau.InitJeu();
    aPlateau.NewCase();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("vueObjetCpt", &aPlateau);
    engine.load(url);

    return app.exec();
}
