
#include <cassert>
#include "Prototype.h"

int main()
{
  // pΪԭ��
  std::unique_ptr<Prototype> p = std::make_unique<ConcretePrototype>();

  // qΪ��¡����
  std::unique_ptr<Prototype> q = p->clone();
  assert(p != q);
}