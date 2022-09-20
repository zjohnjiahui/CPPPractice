
#include <cassert>
#include "Prototype.h"

int main()
{
  // p为原型
  std::unique_ptr<Prototype> p = std::make_unique<ConcretePrototype>();

  // q为克隆生成
  std::unique_ptr<Prototype> q = p->clone();
  assert(p != q);
}