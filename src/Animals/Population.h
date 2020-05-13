#pragma once

#include <string>
#include <cstdint>
#include <iostream>

#include "Mutations/LeafMutation.h"
#include "Mutations/CompoundMutation.h"

class Population {
 public:
  enum ParamType {
    VERY_SMALL,
    SMALL,
    AVERAGE,
    BIG,
    VERY_BIG
  };
  enum TypeName {
    HERBIVORE,
    CARNIVORE
  };
  enum MutationType {
    SIZE,
    SAFETY,
    VELOCITY,
    COVER
  };

  Population() = default;
  Population(Population const &p) = default;

  void applyLifeCircle(int32_t _xPos,
                       int32_t _yPos,
                       int32_t food,
                       int32_t water,
                       int32_t carnivore,
                       int32_t herbivore,
                       ParamType herbSize,
                       ParamType carnSize);

  void mutate(MutationType type);
  void move(int32_t x_pos, int32_t y_pos);

  friend std::ostream &operator<<(std::ostream &os, Population &p);

  TypeName GetType() const;
  void SetType(TypeName type);
  const std::string &GetName() const;
  void SetName(const std::string &name);
  int32_t GetXPos() const;
  void SetXPos(int32_t x_pos);
  int32_t GetYPos() const;
  void SetYPos(int32_t y_pos);
  int32_t GetAnimalAmount() const;
  void SetAnimalAmount(int32_t animal_amount);
  int32_t GetHealth() const;
  void SetHealth(int32_t health);
  int32_t GetProductivity() const;
  void SetProductivity(int32_t productivity);
  int32_t GetBiologyDev() const;
  void SetBiologyDev(int32_t biology_dev);
  ParamType GetSize() const;
  void SetSize(ParamType size);
  ParamType GetSafety() const;
  void SetSafety(ParamType safety);
  ParamType GetVelocity() const;
  void SetVelocity(ParamType velocity);
  ParamType GetCover() const;
  void SetCover(ParamType cover);
 private:
  void addMutation(MutationType type);
  void applyMutation();

  CompoundMutation mutationTree;

  static void switchParam(ParamType &p, int32_t value);

  TypeName type;
  std::string name;
  int32_t xPos = 0, yPos = 0;
  int32_t animalAmount; //[0, 10000]
  int32_t health; //[0, 100] %
  int32_t productivity; //[0, 10] - average amount of children from one parent
  int32_t biologyDev; //[0, 100] %
  ParamType size;
  ParamType safety;
  ParamType velocity;
  ParamType cover;
};