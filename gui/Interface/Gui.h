#pragma once

#include <qt5/QtCore/QObject>
#include <qt5/QtCore/QArgument>
#include <qt5/QtCore/QString>
#include <qt5/QtCore/QVariantList>

#include "Engine/GameEngine.h"
#include "Engine/Subscriber.h"

#include "GUICommands/MoveCommand.h"
#include "GUICommands/MutateCommand.h"
#include "GUICommands/SplitCommand.h"
#include "GUICommands/StopCommand.h"

class Gui : public QObject, public Subscriber {
  Q_OBJECT
  Q_PROPERTY(QVariantList map READ getMap WRITE setMap NOTIFY mapChanged)
  Q_PROPERTY(QVariantList populations READ getPopulations WRITE setPopulations NOTIFY populationsChanged)
  Q_PROPERTY(QVariantList currentPopulation READ getCurrentPopulation WRITE setCurrentPopulation NOTIFY currentPopulationChanged)
  Q_PROPERTY(QVariantList currentCell READ getCurrentCell WRITE setCurrentCell NOTIFY currentCellChanged)

  Q_PROPERTY(QVariant x READ getX WRITE setX NOTIFY xChanged)
  Q_PROPERTY(QVariant y READ getY WRITE setY NOTIFY yChanged)

  Q_PROPERTY(QVariant id READ getID WRITE setID NOTIFY idChanged)

 public:
  explicit Gui(std::shared_ptr<GameEngine> setEngine, QObject *parent = nullptr);

  const QVariantList & getMap();
  void setMap(const QVariantList &setMap);

  const QVariantList & getPopulations();
  void setPopulations(const QVariantList &setPopulations);

  const QVariantList & getCurrentPopulation();
  void setCurrentPopulation(const QVariantList &setPopulation);

  const QVariantList & getCurrentCell();
  void setCurrentCell(const QVariantList &setCurrentCell);

  const QVariant & getX();
  void setX(const QVariant &setX);

  const QVariant & getY();
  void setY(const QVariant &setY);

  const QVariant & getID();
  void setID(const QVariant &setID);

  std::shared_ptr<GameEngine> getEngine();

  void update(bool end) override;

 public slots:
  void select();
  void migrate();
  void multiply();
  void mutate(int type);
  void stop();
  bool checkPopulation(int posX, int posY);

 signals:
  void mapChanged();
  void populationsChanged();
  void currentPopulationChanged();
  void currentCellChanged();
  void xChanged();
  void yChanged();
  void idChanged();
  void requestUpdate();
  void endGame();

 private:
  QVariantList map;
  QVariantList populations;

  QVariantList currentPopulation;
  QVariantList currentCell;

  QVariant x;
  QVariant y;

  QVariant id;

  std::shared_ptr<GameEngine> engine;

  std::shared_ptr<Population> selectedPopulation;

  std::shared_ptr<MoveCommand> moveCommand;
  std::shared_ptr<SplitCommand> splitCommand;
  std::shared_ptr<MutateCommand> mutateCommand;
  std::shared_ptr<StopCommand> stopCommand;

  void fillMap();
  void fillPopulations();

  void updatePopulations();
};
