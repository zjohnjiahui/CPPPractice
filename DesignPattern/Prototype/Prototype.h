#pragma once
#include <memory>

// 要点：
// virtual clone()函数
// virtual 析构函数
// clone() 函数中调用自身的拷贝构造函数

class Prototype
{
private:

public:
  virtual std::unique_ptr<Prototype> clone()=0;

  Prototype() = default;
  Prototype(const Prototype& P) = default;
  virtual ~Prototype() = default;
};

class ConcretePrototype :public Prototype
{
private:
public:
  virtual std::unique_ptr<Prototype> clone() override
  {
    // 调用拷贝构造函数，也是一种多态拷贝构造函数
    // ptr<Derived>隐式转换为ptr<Base>
    return std::make_unique<ConcretePrototype>(*this); 
  }
  ConcretePrototype() = default;
  ConcretePrototype(const ConcretePrototype&) = default;
  ~ConcretePrototype() = default;
};
