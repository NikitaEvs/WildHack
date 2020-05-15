#pragma once

class Subscriber {
 public:
  ~Subscriber() = default;

  virtual void update(bool end = false) = 0;
};
