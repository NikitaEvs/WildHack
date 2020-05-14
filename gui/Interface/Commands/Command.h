#pragma once

#include <memory>

#include "Engine/GameEngine.h"

class Command {
 public:
  Command() = default;

  ~Command() = default;

  virtual bool execute() = 0;

  void setReceiver(std::shared_ptr<GameEngine> engine);

 private:
  std::shared_ptr<GameEngine> receiver = nullptr;
};
