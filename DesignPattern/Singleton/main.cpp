#include "Singleton.h"
#include <cassert>
int main()
{
  Singleton* instance_1 = Singleton::Instance();
  Singleton* instance_2 = Singleton::Instance();
  assert(instance_1 == instance_1);
   
  DerivedSingleton* a = DerivedSingleton::Instance();
  DerivedSingleton* b = DerivedSingleton::Instance();
  assert(a == b);

  return 0;
}