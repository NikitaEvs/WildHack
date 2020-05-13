#include "Handler.h"

void Handler::setNext(std::shared_ptr<Handler> _next) {
  next = _next;
}
void Handler::setPopulation(std::shared_ptr<Population> _population) {
  population = _population;
}

void Handler::handle() {
  if(population != nullptr){
    change();
    if(next != nullptr){
      next->handle();
    } else {
      throw "It was the last handler";
    }
  }else{
    throw "There is no population to change";
  }
}