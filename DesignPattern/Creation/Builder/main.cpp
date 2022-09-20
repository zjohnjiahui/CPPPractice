#include "Director.h"
#include <iostream>

int main()
{
  StoneHouseBuilder builder;
  Director director;
  std::unique_ptr<House> up =  director.build(builder);

  return 0;
}