#pragma once

#include <memory>

#include "Command.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class MutateCommand : public Command {
 public:
  explicit MutateCommand(std::shared_ptr<GameEngine> engine);

  void setGoal(std::shared_ptr<Population> setGoal);

  void setType(Population::MutationType type);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;
  Population::MutationType mutationType;
};
