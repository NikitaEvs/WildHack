#pragma once

#include <memory>

#include <qt5/QtCore/QObject>
#include <qt5/QtCore/QArgument>
#include <qt5/QtCore/QString>
#include <qt5/QtCore/QVariantList>

#include "Command.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class MoveCommand : public QObject, public Command {
  Q_OBJECT

 public:
  explicit MoveCommand(QObject *parent = nullptr);

  void setDestination(size_t destinationX, size_t destinationY);

  void setGoal(std::shared_ptr<Population> population);

  Q_INVOKABLE bool execute() override;
  Q_INVOKABLE void kek();

 private:
  std::shared_ptr<GameEngine> receiver;
  std::shared_ptr<Population> goal;

  size_t x = 0, y = 0;
};