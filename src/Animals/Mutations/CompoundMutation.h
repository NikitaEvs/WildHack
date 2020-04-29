#ifndef PEACH_SRC_ANIMALS_MUTATIONS_COMPOUNDMUTATION_H_
#define PEACH_SRC_ANIMALS_MUTATIONS_COMPOUNDMUTATION_H_

#include <vector>

#include "MutationComponent.h"

class CompoundMutation : public MutationComponent {
 private:
  std::vector<std::shared_ptr<MutationComponent> > children;
 public:
  CompoundMutation();
  void add(std::shared_ptr<MutationComponent> m);
  void getMutation() override;
  void print(std::ostream &os) override;
};

#endif //PEACH_SRC_ANIMALS_MUTATIONS_COMPOUNDMUTATION_H_
