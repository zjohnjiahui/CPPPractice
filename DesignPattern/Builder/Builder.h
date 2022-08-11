#pragma once
#include <memory>
#include "House.h"

class HouseBuilder
{
protected:
  std::unique_ptr<House> pHouse;

public:
  HouseBuilder(): pHouse(std::make_unique<House>()){ }

  virtual void buildWall() = 0;
  virtual void buildFloor() = 0;
  virtual void buildCeil() = 0;
  virtual void buildWindow() = 0;
  virtual void buildDoor() = 0;

  std::unique_ptr<House> getResult() {
    std::unique_ptr<House> ret = std::move(pHouse);
    pHouse.reset(new House());
    return ret; 
  }

  virtual ~HouseBuilder() = default;
};

class StoneHouseBuilder:public HouseBuilder
{
public:
  void buildWall() override {
    for (int i = 0; i < 4; ++i)
    {
      Wall w(Stone);
      pHouse->addWall(w);
    } 
  }
  void buildFloor() override { pHouse->addFloor(Floor(Stone)); }
  void buildCeil() override { pHouse->addCeil(Ceil(Stone)); }
  void buildWindow() override { 
    for (int i = 0; i < 2; ++i) {
      pHouse->addWindow(Window(Wood));
    } 
  }
  void buildDoor() override { pHouse->addDoor(Door(Wood)); }
};

class WoodHouseBuilder:public HouseBuilder
{
public:
  void buildWall() override {
    for (int i = 0; i < 4; ++i)
    {
      Wall w(Wood);
      pHouse->addWall(w);
    }
  }
  void buildFloor() override { pHouse->addFloor(Floor(Wood)); }
  void buildCeil() override { pHouse->addCeil(Ceil(Wood)); }
  void buildWindow() override {
    for (int i = 0; i < 2; ++i) {
      pHouse->addWindow(Window(Wood));
    }
  }
  void buildDoor() override { pHouse->addDoor(Door(Wood)); }
};