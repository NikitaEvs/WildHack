#include "Population.h"
#include "RandomGenerator.h"
#include "Config.h"

void Population::applyLifeCircle(int32_t _xPos,
                                 int32_t _yPos,
                                 int32_t food,
                                 int32_t water,
                                 int32_t carnivore,
                                 int32_t herbivore,
                                 ParamType herbSize,
                                 ParamType carnSize) {
  xPos = _xPos;
  yPos = _yPos;

  //if there's no food or water someone must die
  int32_t nutrition = (food + 1.5 * water) / 250;
  if (type == Population::TypeName::CARNIVORE) {
    nutrition = (herbivore * 100 / Config::getInstance().getMaxAmount(HERBIVORE, herbSize) + water) / 200;
  }
  if (nutrition < 75) {
    animalAmount = (animalAmount * (nutrition + 25)) / 100;
  }
  // carnivore animal can eat some animals from the population
  int32_t wasEaten = carnivore * 100 / Config::getInstance().getMaxAmount(CARNIVORE, carnSize);
  switch (velocity) {
    case VERY_SMALL:wasEaten = wasEaten * 1 / 10;
      break;
    case SMALL:wasEaten = wasEaten * 1 / 5;
      break;
    case AVERAGE:wasEaten = wasEaten * 3 / 10;
      break;
    case BIG:wasEaten = wasEaten * 2 / 5;
      break;
    case VERY_BIG:wasEaten = wasEaten * 1 / 2;
      break;
  }
  animalAmount = (animalAmount * wasEaten) / 100;
  // but new animals are born
  animalAmount = animalAmount * (100 + productivity) / 100;

  //some game points
  int32_t k = (productivity * (static_cast<int32_t>(size) + static_cast<int32_t>(cover))
      + health * (static_cast<int32_t>(velocity) + static_cast<int32_t>(safety))) / 2000;
  biologyDev = biologyDev * (100 + k) / 100;
}

void Population::mutate(MutationType type) {
  addMutation(type);
  applyMutation();
}

void Population::move(int32_t x_pos, int32_t y_pos) {
  xPos = x_pos;
  yPos = y_pos;
}

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

void Population::addMutation(Population::MutationType type) {
  LeafMutation lm;
  switch (type) {
    case SIZE:lm.size = RandomGenerator::getInstance().randNormalInt(0, 1);
      break;
    case SAFETY:lm.safety = RandomGenerator::getInstance().randNormalInt(0, 1);
      break;
    case COVER:lm.cover = RandomGenerator::getInstance().randNormalInt(0, 1);
      break;
    case VELOCITY:lm.velocity = RandomGenerator::getInstance().randNormalInt(0, 1);
      break;
  }
  lm.health = RandomGenerator::getInstance().randNormalInt(0, 5);
  lm.productivity = RandomGenerator::getInstance().randNormalInt(0, 5);
  mutationTree.add(std::make_shared<LeafMutation>(lm));
}

void Population::applyMutation() {
  mutationTree.getMutation();
  health *= (100 + mutationTree.health);
  productivity *= (100 + mutationTree.productivity);
  health /= 100;
  productivity /= 100;
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