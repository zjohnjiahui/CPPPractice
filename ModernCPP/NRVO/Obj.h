#pragma once
#include <iostream>
#include <vector>

class Obj
{
public:

  Obj();

  Obj(const Obj& other);

  Obj(Obj&& other);

  Obj& operator=(const Obj& other);

  Obj& operator=(Obj&& other);

  ~Obj();

private:

};

class ObjContainer
{
public:
  std::vector<Obj> locals;
  ObjContainer() {
    locals.resize(2);
  }

  std::vector<Obj> getLocals() {
    return locals;
  }
};
