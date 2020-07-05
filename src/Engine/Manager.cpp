#include "Manager.h"

void Manager::subscribe(std::shared_ptr<Subscriber> subscriber) {
  subscribers.push_back(std::move(subscriber));
}

void Manager::notifyDataChanged(bool end) {
  for (const auto & subscriber : subscribers) {
    subscriber -> update(end);
  }
}
