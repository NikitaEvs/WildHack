#pragma once

#include <memory>

#include "Command.h"
#include "../GameEngine.h"
#include "Population.h"

class MoveCommand : public Command {
 public:
  MoveCommand(std::shared_ptr<GameEngine> engine,
              std::shared_ptr<Population> population);

  void setDestination(size_t destinationX, size_t destinationY);

  bool execute() override;

 private:
  std::shared_ptr<GameEngine> receiver;
  std::shared_ptr<Population> goal;

  size_t x = 0, y = 0;
};