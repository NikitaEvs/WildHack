#include "CellType.h"

std::ostream& operator<<(std::ostream &os, const CellType &cell) {
  std::string cellTypeStr, climateTypeStr;

  switch (cell.type) {
    case CellType::WATER:
      cellTypeStr = "WATER";
      break;
    case CellType::FOREST:
      cellTypeStr = "FOREST";
      break;
    case CellType::STEPPE:
      cellTypeStr = "STEPPE";
      break;
    case CellType::TUNDRA:
      cellTypeStr = "TUNDRA";
      break;
  }

  switch (cell.climate) {
    case CellType::HOT:
      climateTypeStr = "HOT";
      break;
    case CellType::TEMPERATE:
      climateTypeStr = "TEMPERATE";
      break;
    case CellType::COLD:
      climateTypeStr = "COLD";
      break;
  }

  os  << "                 ~~~~~                 "      <<  std::endl
      << climateTypeStr << " "  << cellTypeStr          <<  std::endl
      << "~ WATER LEVEL:     "  << cell.waterLevel      <<  std::endl
      << "~ PLANTS COUNT:    "  << cell.plantsCount     <<  std::endl
      << "~ CARNIVORE COUNT: "  << cell.carnivoreCount  <<  std::endl
      << "~ HERBIVORE COUNT: "  << cell.herbivoreCount  <<  std::endl
      << "                 ~~~~~                 "      <<  std::endl;

  return os;
}


int32_t CellType::getWaterLevel() const {
  return waterLevel;
}

void CellType::setWaterLevel(int32_t newWaterLevel) {
  waterLevel = newWaterLevel;
}


int32_t CellType::getPlantsCount() const {
  return plantsCount;
}

void CellType::setPlantsCount(int32_t newPlantsCount) {
  plantsCount = newPlantsCount;
}


int32_t CellType::getCarnivoreCount() const {
  return carnivoreCount;
}

void CellType::setCarnivoreCount(int32_t newCarnivoreCount) {
  carnivoreCount = newCarnivoreCount;
}


int32_t CellType::getHerbivoreCount() const {
  return herbivoreCount;
}

void CellType::setHerbivoreCount(int32_t newHerbivoreCount) {
  herbivoreCount = newHerbivoreCount;
}


CellType::cellType CellType::getType() const {
  return type;
}

void CellType::setType(CellType::cellType newType) {
  type = newType;
}


CellType::climateType CellType::getClimate() const {
  return climate;
}

void CellType::setClimate(CellType::climateType newClimate) {
  climate = newClimate;
}

std::shared_ptr<Population> CellType::getCurrentPopulation() const {
  return currentPopulation;
}

void CellType::setCurrentPopulation(std::shared_ptr<Population> current_population) {
  currentPopulation = std::move(current_population);
}
