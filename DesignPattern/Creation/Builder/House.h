#pragma once
#include <vector>
#include <array>

enum Material { Wood, Stone, Brick, Marble, Gold, Steel };

// ��������Ҫ�������ÿ��������в���������չ��˼�룬û�аѲ����ӽ�ȥ

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

// ��Ʒ�࣬�ṩ�޸ı���Ʒ�Ľӿ�

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
