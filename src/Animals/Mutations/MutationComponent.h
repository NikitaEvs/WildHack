#pragma once

#include <cstdint>
#include <iosfwd>
#include <memory>

class MutationComponent {
 public:
  int32_t health = 1;
  int32_t productivity = 1;
  int32_t size = 0;
  int32_t safety = 0;
  int32_t velocity = 0;
  int32_t cover = 0;

  MutationComponent() = default;
  virtual void getMutation() = 0;
  virtual void print(std::ostream &os) = 0;
};
