#ifndef PEACH_SRC_MAP_MAP_H_
#define PEACH_SRC_MAP_MAP_H_

#include <memory>
#include <vector>

#include "CellType.h"
#include "CellTypeDirector.h"
#include "CellTypeBuilder.h"
#include "util/Random.h"
#include "json/json.hpp"

class Map {
 private:
  std::vector<std::vector<std::shared_ptr<CellType> > > map;

 public:
  typedef std::vector<std::vector<std::shared_ptr<CellType> > >::iterator iterator;

  Map(size_t columnNumber, size_t rowNumber);
  Map() = default;

  iterator begin();
  iterator end();
  std::vector<std::shared_ptr<CellType> >& operator[](size_t index);

  void loadFrom(std::istream& file);
  void saveTo(std::ostream& out);

  void addCell(std::shared_ptr<CellType> &&cell, size_t row, size_t column);
  void generate();

  size_t getHeight();
  size_t getWidth();
};

#endif //PEACH_SRC_MAP_MAP_H_
