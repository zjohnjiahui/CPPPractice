#pragma once
#include <memory>

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
    // ���ÿ������캯����Ҳ��һ�ֶ�̬�������캯��
    // ptr<Derived>��ʽת��Ϊptr<Base>
    return std::make_unique<ConcretePrototype>(*this); 
  }
  ConcretePrototype() = default;
  ConcretePrototype(const ConcretePrototype&) = default;
  ~ConcretePrototype() = default;
};