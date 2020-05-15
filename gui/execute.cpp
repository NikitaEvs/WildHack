#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Interface/Gui.h"
#include "Interface/Commands/MoveCommand.h"

#include "Interface/Models/PlayerScoreModel.h"

#include "Engine/GameEngine.h"
#include "Engine/Manager.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  QQmlApplicationEngine engine;

  std::shared_ptr<GameEngine> gameEngine = std::make_shared<GameEngine>();
  std::shared_ptr<Gui> gui = std::make_shared<Gui>(gameEngine);

  std::shared_ptr<Manager> manager = std::make_shared<Manager>();
  manager -> subscribe(gui);

  gameEngine -> setManager(manager);

  PlayerScoreModel model(gameEngine);

  engine.rootContext() -> setContextProperty("playerModel", &model);
  engine.rootContext() -> setContextProperty("gui", gui.get());

  engine.load(QUrl(QStringLiteral("../../resources/layout/main.qml")));

  return app.exec();
}