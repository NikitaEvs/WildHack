#pragma once

#include <memory>

#include "Command.h"
#include "Engine/GameEngine.h"
#include "Population.h"

class MutateCommand : public Command {
 public:
  MutateCommand(std::shared_ptr<GameEngine> engine,
                std::shared_ptr<Population> population,
                Population::MutationType type);

  bool execute() override;

 private:
  std::shared_ptr<Population> goal;
  Population::MutationType mutationType;
};
