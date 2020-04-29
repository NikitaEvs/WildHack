#include <iostream>
#include "LeafMutation.h"

LeafMutation::LeafMutation() = default;

void LeafMutation::getMutation() {}

void LeafMutation::print(std::ostream &os) {
  os << "HEALTH SHARE " << health << " / 10" << std::endl;
  os << "PRODUCTIVITY SHARE " <<  productivity << " / 10" << std::endl;
  os << "WELLBEING SHARE " <<  wellBeing << " / 10" << std::endl;
  os << "SIZE SWITCH " <<  size << std::endl;
  os << "SAFETY SWITCH " <<  safety << std::endl;
  os << "VELOCITY SWITCH " <<  velocity << std::endl;
  os << "COVER SWITCH " <<  cover << std::endl;
}
