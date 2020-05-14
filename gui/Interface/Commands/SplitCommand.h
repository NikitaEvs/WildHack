#pragma once

#include "Command.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class SplitCommand : public Command {
 public:
  SplitCommand(std::shared_ptr<GameEngine> engine,
               std::shared_ptr<Population> population);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;
};
