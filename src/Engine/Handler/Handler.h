#pragma once

#include <memory>
class Handler{
 public:
  void handle();
  void setNext(Handler _next);
 private:
  std::shared_ptr<Handler> next = nullptr;
};