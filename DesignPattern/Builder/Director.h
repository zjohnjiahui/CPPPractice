#pragma once
#include "Builder.h"

class Director 
{
private:
public:
  std::unique_ptr<House> build(HouseBuilder& builder)
  {
    builder.buildFloor();
    builder.buildWall();
    builder.buildCeil();
    builder.buildWindow();
    builder.buildDoor();
    return builder.getResult();
  }
};