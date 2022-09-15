#include "Factory.h"
#include "Product.h"

int main(int argc, char* argv[])
{
  std::unique_ptr<Factory> fac = std::make_unique<ConcreteFactory>();
  std::unique_ptr<Product> p = fac->CreateProduct();

  return 0;
}