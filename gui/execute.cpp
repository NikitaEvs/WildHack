#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Interface/Gui.h"
#include "Interface/Commands/MoveCommand.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  Gui gui;
  MoveCommand moveCommand;
  moveCommand.setReceiver(gui.getEngine());

  engine.rootContext() -> setContextProperty("gui", &gui);

  engine.load(QUrl(QStringLiteral("../../resources/layout/main.qml")));

  return app.exec();
}