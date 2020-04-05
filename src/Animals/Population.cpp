#include "Population.h"

Population::Population() = default;
Population::Population(Population const &p) {
  type = p.type;
  name = p.name;
  animalAmount = p.animalAmount;
  health = p.health;
  productivity = p.productivity;
  wellBeing = p.wellBeing;
  biologyDev = p.biologyDev;
  size = p.size;
  safety = p.safety;
  velocity = p.velocity;
  cover = p.cover;
  xPos = p.xPos;
  yPos = p.yPos;
}
void Population::move(int32_t x, int32_t y) {
  xPos = x;
  yPos = y;
}
void Population::dieOut(int32_t amount) {
  animalAmount -= amount * animalAmount / 100;
}

std::ostream &operator<<(std::ostream &os, Population &p) {
  std::string pSize, pSafe, pVel, pCov;
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
  os << p.type << " " << pSize << " " << p.name << "\n"
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
}
