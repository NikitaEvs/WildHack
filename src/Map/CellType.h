#ifndef SRC_CELLTYPE_H_
#define SRC_CELLTYPE_H_

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

    int32_t waterLevel = 0;
    int32_t plantsCount = 0;
    int32_t carnivoreCount = 0;
    int32_t herbivoreCount = 0;
    cellType type;
    climateType climate;

    friend std::ostream& operator << (std::ostream &os, const CellType &cell);
};

#endif
