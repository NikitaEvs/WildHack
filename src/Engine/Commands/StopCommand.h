#pragma once

#include <memory>

#include "Command.h"
#include "../GameEngine.h"
#include "Population.h"

class StopCommand : public Command {
 public:
  StopCommand(std::shared_ptr<GameEngine> engine);

  bool execute() override;
};