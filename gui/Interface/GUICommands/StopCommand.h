#pragma once

#include <memory>

#include "GUICommand.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class StopCommand : public GUICommand {
 public:
  StopCommand(std::shared_ptr<GameEngine> engine);

  bool execute() override;
};
