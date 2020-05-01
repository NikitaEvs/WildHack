#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Interface/Gui.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  Gui gui;

  engine.rootContext() -> setContextProperty("gui", &gui);
  engine.load(QUrl(QStringLiteral("../../resources/layout/main.qml")));

  return app.exec();
}