#include "Population.h"
#include "RandomGenerator.h"

void Population::switchParam(ParamType &p, int32_t value) {
  switch (value) {
    case -1:
      if (p > VERY_SMALL) {
        p = static_cast<ParamType>(static_cast<int32_t>(p) - 1);
      }
      break;
    case 1:
      if (p < VERY_BIG) {
        p = static_cast<ParamType>(static_cast<int32_t>(p) + 1);
      }
      break;
    default:break;
  }
}

void Population::move(int32_t x, int32_t y) {
  xPos = x;
  yPos = y;
}
void Population::dieOut(int32_t amount) {
  animalAmount -= amount * animalAmount / 100;
}

void Population::addMutation() {
  LeafMutation lm;
  lm.health = RandomGenerator::getInstance().randNormalInt(0, 5);
  lm.productivity = RandomGenerator::getInstance().randNormalInt(0, 5);
  lm.wellBeing = RandomGenerator::getInstance().randNormalInt(0, 5);
  lm.size = RandomGenerator::getInstance().randNormalInt(0, 1);
  lm.safety = RandomGenerator::getInstance().randNormalInt(0, 1);
  lm.velocity = RandomGenerator::getInstance().randNormalInt(0, 1);
  lm.cover = RandomGenerator::getInstance().randNormalInt(0, 1);
  mutationTree.add(std::make_shared<LeafMutation>(lm));
}

void Population::applyMutation() {
  mutationTree.getMutation();
  health *= (100 + mutationTree.health);
  productivity *= (100 + mutationTree.productivity);
  wellBeing *= (100 + mutationTree.wellBeing);
  health /= 100;
  productivity /= 100;
  wellBeing /= 100;
  switchParam(size, mutationTree.size);
  switchParam(safety, mutationTree.safety);
  switchParam(velocity, mutationTree.velocity);
  switchParam(cover, mutationTree.cover);
}

std::ostream &operator<<(std::ostream &os, Population &p) {
  std::string pSize, pSafe, pVel, pCov, pType;
  switch (p.type) {
    case Population::HERBIVORE:pType = "HERBIVORE";
      break;
    case Population::CARNIVORE:pType = "CARNIVORE";
      break;
  }
  
  switch (p.size) {
    case Population::VERY_SMALL:pSize = "VERY_SMALL";
      break;
    case Population::SMALL:pSize = "SMALL";
      break;
    case Population::AVERAGE:pSize = "AVERAGE";
      break;
    case Population::BIG:pSize = "BIG";
      break;
    case Population::VERY_BIG:pSize = "VERY_BIG";
      break;
  }

  switch (p.safety) {
    case Population::VERY_SMALL:pSafe = "VERY_SMALL";
      break;
    case Population::SMALL:pSafe = "SMALL";
      break;
    case Population::AVERAGE:pSafe = "AVERAGE";
      break;
    case Population::BIG:pSafe = "BIG";
      break;
    case Population::VERY_BIG:pSafe = "VERY_BIG";
      break;
  }

  switch (p.velocity) {
    case Population::VERY_SMALL:pVel = "VERY_SMALL";
      break;
    case Population::SMALL:pVel = "SMALL";
      break;
    case Population::AVERAGE:pVel = "AVERAGE";
      break;
    case Population::BIG:pVel = "BIG";
      break;
    case Population::VERY_BIG:pVel = "VERY_BIG";
      break;
  }

  switch (p.cover) {
    case Population::VERY_SMALL:pCov = "VERY_SMALL";
      break;
    case Population::SMALL:pCov = "SMALL";
      break;
    case Population::AVERAGE:pCov = "AVERAGE";
      break;
    case Population::BIG:pCov = "BIG";
      break;
    case Population::VERY_BIG:pCov = "VERY_BIG";
      break;
  }
  os << pType << " " << pSize << " " << p.name << "\n"
     << "animalAmount " << p.animalAmount << "\n"
     << "health       " << p.health << "\n"
     << "productivity " << p.productivity << "\n"
     << "wellBeing    " << p.wellBeing << "\n"
     << "biologyDev   " << p.biologyDev << "\n"
     << "safety       " << pSafe << "\n"
     << "velocity     " << pVel << "\n"
     << "cover        " << pCov << "\n"
     << "xPos         " << p.xPos << "\n"
     << "yPos         " << p.yPos << "\n";
  os << "MUTATIONS" << std::endl;
  p.mutationTree.getMutation();
  p.mutationTree.print(os);
}


Population::TypeName Population::GetType() const {
  return type;
}
void Population::SetType(Population::TypeName type) {
  Population::type = type;
}
const std::string &Population::GetName() const {
  return name;
}
void Population::SetName(const std::string &name) {
  Population::name = name;
}
int32_t Population::GetXPos() const {
  return xPos;
}
void Population::SetXPos(int32_t x_pos) {
  xPos = x_pos;
}
int32_t Population::GetYPos() const {
  return yPos;
}
void Population::SetYPos(int32_t y_pos) {
  yPos = y_pos;
}
int32_t Population::GetAnimalAmount() const {
  return animalAmount;
}
void Population::SetAnimalAmount(int32_t animal_amount) {
  animalAmount = animal_amount;
}
int32_t Population::GetHealth() const {
  return health;
}
void Population::SetHealth(int32_t health) {
  Population::health = health;
}
int32_t Population::GetProductivity() const {
  return productivity;
}
void Population::SetProductivity(int32_t productivity) {
  Population::productivity = productivity;
}
int32_t Population::GetWellBeing() const {
  return wellBeing;
}
void Population::SetWellBeing(int32_t well_being) {
  wellBeing = well_being;
}
int32_t Population::GetBiologyDev() const {
  return biologyDev;
}
void Population::SetBiologyDev(int32_t biology_dev) {
  biologyDev = biology_dev;
}
Population::ParamType Population::GetSize() const {
  return size;
}
void Population::SetSize(Population::ParamType size) {
  Population::size = size;
}
Population::ParamType Population::GetSafety() const {
  return safety;
}
void Population::SetSafety(Population::ParamType safety) {
  Population::safety = safety;
}
Population::ParamType Population::GetVelocity() const {
  return velocity;
}
void Population::SetVelocity(Population::ParamType velocity) {
  Population::velocity = velocity;
}
Population::ParamType Population::GetCover() const {
  return cover;
}
void Population::SetCover(Population::ParamType cover) {
  Population::cover = cover;
}