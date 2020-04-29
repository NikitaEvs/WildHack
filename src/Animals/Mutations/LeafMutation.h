#ifndef PEACH_SRC_ANIMALS_MUTATIONS_LEAFMUTATION_H_
#define PEACH_SRC_ANIMALS_MUTATIONS_LEAFMUTATION_H_

#include "MutationComponent.h"

class LeafMutation : public MutationComponent {
 public:
  LeafMutation();
  void getMutation() override;
  void print(std::ostream &os) override;
};

#endif //PEACH_SRC_ANIMALS_MUTATIONS_LEAFMUTATION_H_
