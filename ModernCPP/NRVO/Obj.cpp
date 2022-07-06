#include "Obj.h"

Obj::Obj() {
  std::cout << "Obj()" << " " << this << std::endl;
}

Obj::Obj(const Obj& other) {
  std::cout << "Obj(const Obj&)" << " " << &other << " " << this << std::endl;
}

Obj::Obj(Obj&& other) {
  std::cout << "Obj(Obj&&)" << " " << &other << " " << this << std::endl;
}

Obj& Obj::operator=(const Obj& other) {
  if (this != &other)
  {

  }
  std::cout << "operator=(const Obj&)" << " " << &other << " " << this << std::endl;
  return *this;
}

Obj& Obj::operator=(Obj&& other) {
  if (this != &other)
  {

  }
  std::cout << "operator=(Obj&&)" << " " << &other << " " << this << std::endl;
  return *this;
}

Obj::~Obj() {
  std::cout << "~Obj()" << " " << this << std::endl;
}
