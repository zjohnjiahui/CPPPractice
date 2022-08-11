#include "Director.h"

int main()
{
  StoneHouseBuilder builder;
  Director director;
  std::unique_ptr<House> up =  director.build(builder);

  return 0;
}