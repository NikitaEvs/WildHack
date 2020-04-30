#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Interface/Gui.h"
#include "util/Config.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  Gui gui;

  engine.rootContext() -> setContextProperty("gui", &gui);
  engine.load(QUrl(QStringLiteral("../../resources/layout/main.qml")));

  return app.exec();
}