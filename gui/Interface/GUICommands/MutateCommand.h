#pragma once

#include <memory>

#include "GUICommand.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class MutateCommand : public GUICommand {
 public:
  explicit MutateCommand(std::shared_ptr<GameEngine> engine);

  void setGoal(std::shared_ptr<Population> setGoal);

  void setType(Population::MutationType type);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;
  Population::MutationType mutationType;
};
