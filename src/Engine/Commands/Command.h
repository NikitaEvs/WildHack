#pragma once

#include <memory>

#include "../GameEngine.h"

class Command {
 public:
  virtual ~Command() = default;

  virtual bool execute() = 0;

  void setReceiver(std::shared_ptr<GameEngine> engine);

 private:
  std::shared_ptr<GameEngine> receiver = nullptr;
};
