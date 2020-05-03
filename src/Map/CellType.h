#pragma once

#include <cstdint>
#include <string>
#include <iostream>

class CellType {
 public:
    enum cellType {
      WATER,
      STEPPE,
      FOREST,
      TUNDRA
    };

    enum climateType {
      HOT,
      TEMPERATE,
      COLD
    };

    int32_t getWaterLevel() const;
    void setWaterLevel(int32_t newWaterLevel);

    int32_t getPlantsCount() const;
    void setPlantsCount(int32_t newPlantsCount);

    int32_t getCarnivoreCount() const;
    void setCarnivoreCount(int32_t newCarnivoreCount);

    int32_t getHerbivoreCount() const;
    void setHerbivoreCount(int32_t newHerbivoreCount);

    cellType getType() const;
    void setType(cellType newType);

    climateType getClimate() const;
    void setClimate(climateType newClimate);

  friend std::ostream& operator << (std::ostream &os, const CellType &cell);

 private:
  int32_t waterLevel = 0;
  int32_t plantsCount = 0;
  int32_t carnivoreCount = 0;
  int32_t herbivoreCount = 0;
  cellType type;
  climateType climate;
};
