#pragma once

#include <vector>
#include <memory>

#include "Subscriber.h"

class Manager {
 public:
  void subscribe(std::shared_ptr<Subscriber> subscriber);

  void notifyDataChanged(bool end = false);

 private:
  std::vector<std::shared_ptr<Subscriber> > subscribers;
};