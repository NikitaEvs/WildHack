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