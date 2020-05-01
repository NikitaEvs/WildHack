#ifndef PEACH_SRC_ANIMALS_MUTATIONS_MUTATIONCOMPONENT_H_
#define PEACH_SRC_ANIMALS_MUTATIONS_MUTATIONCOMPONENT_H_

#include <cstdint>
#include <iosfwd>
#include <memory>

class MutationComponent {
 public:
  int32_t health = 1;
  int32_t productivity = 1;
  int32_t wellBeing = 1;
  int32_t size = 0;
  int32_t safety = 0;
  int32_t velocity = 0;
  int32_t cover = 0;

  MutationComponent() = default;
  virtual void getMutation() = 0;
  virtual void print(std::ostream &os) = 0;
};

#endif //PEACH_SRC_ANIMALS_MUTATIONS_MUTATIONCOMPONENT_H_
