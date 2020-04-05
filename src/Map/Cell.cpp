#include "Cell.h"

std::ostream& operator<<(std::ostream &os, const Cell &cell) {
  std::string cellTypeStr, climateTypeStr;

  switch (cell.type) {
    case Cell::WATER:
      cellTypeStr = "WATER";
      break;
    case Cell::FOREST:
      cellTypeStr = "FOREST";
      break;
    case Cell::STEPPE:
      cellTypeStr = "STEPPE";
      break;
    case Cell::TUNDRA:
      cellTypeStr = "TUNDRA";
      break;
  }

  switch (cell.climate) {
    case Cell::HOT:
      climateTypeStr = "HOT";
      break;
    case Cell::TEMPERATE:
      climateTypeStr = "TEMPERATE";
      break;
    case Cell::COLD:
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