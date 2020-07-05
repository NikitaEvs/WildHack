#pragma once

#include <memory>

#include "Engine/GameEngine.h"

class GUICommand {
 public:
  explicit GUICommand(std::shared_ptr<GameEngine> engine);

  GUICommand() = default;

  ~GUICommand() = default;

  virtual bool execute() = 0;

  void setReceiver(std::shared_ptr<GameEngine> engine);

  void setID(int32_t setID);

 protected:
  std::shared_ptr<GameEngine> receiver = nullptr;

  int32_t id = 0;
};
