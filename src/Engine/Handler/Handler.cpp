#include "Handler.h"

void Handler::setNext(std::shared_ptr<Handler> _next) {
  next = std::move(_next);
}
void Handler::setPopulation(std::shared_ptr<Population> _population) {
  population = std::move(_population);
}

void Handler::handle() {
  if (population != nullptr) {
    change();
    if (next != nullptr) {
      next->handle();
    } else {
      throw std::runtime_error("It was the last handler");
    }
  } else {
    throw std::runtime_error("There is no population to change");
  }
}