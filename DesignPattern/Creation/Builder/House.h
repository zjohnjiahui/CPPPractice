#pragma once
#include <vector>
#include <array>

enum Material { Wood, Stone, Brick, Marble, Gold, Steel };

// 建房子需要的组件，每种组件都有参数，方便展现思想，没有把参数加进去

class Wall
{
public:
  Wall(Material ma_) :ma(ma_){}
private:
  Material ma;
  //std::array<float,3> pos;
  //std::array<float,3> direction;
  //int height;
  //int width;
  //int thickness;
};

class Floor
{
public:
  Floor(Material ma_) :ma(ma_) {}
private:
  Material ma;
  // int thickness;
};

class Ceil
{
public:
  Ceil(Material ma_) :ma(ma_) {}
private:
  Material ma;
  // int thickness;
};

class Window
{
public:
  Window(Material ma_) :ma(ma_) {}
private:
  Material ma;
  //std::array<float, 3> pos;
  //int height;
  //int width;
};

class Door
{
public:
  Door(Material ma_) :ma(ma_) {}
private:
  Material ma;
  //std::array<float, 3> pos;
  //int height;
  //int width;
};

// 产品类，提供修改本产品的接口

class House
{
private:
  std::vector<Wall> walls;
  std::vector<Floor> floors;
  std::vector<Ceil> ceils;
  std::vector<Window> windows;
  std::vector<Door> doors;

public:
  void addWall(const Wall& wall) { this->walls.push_back(wall); }
  void addFloor(const Floor& floor) { this->floors.push_back(floor); }
  void addCeil(const Ceil& ceil) {this->ceils.push_back(ceil) ; }
  void addWindow(const Window& window) { this->windows.push_back(window); }
  void addDoor(const Door& door) { this->doors.push_back(door); };
};
