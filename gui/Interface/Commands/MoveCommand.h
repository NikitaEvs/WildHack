#pragma once

#include <memory>

#include "Command.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class MoveCommand : public Command {
 public:
  MoveCommand() = default;

  void setGoal(std::shared_ptr<Population> setGoal);

  void setDestination(size_t destinationX, size_t destinationY);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;

  size_t x = 0, y = 0;
};