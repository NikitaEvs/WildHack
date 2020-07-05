#pragma once

#include "GUICommand.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class SplitCommand : public GUICommand {
 public:
  explicit SplitCommand(std::shared_ptr<GameEngine> engine);

  void setGoal(std::shared_ptr<Population> setGoal);

  void setDestination(size_t destinationX, size_t destinationY);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;

  size_t x = 0, y = 0;
};
