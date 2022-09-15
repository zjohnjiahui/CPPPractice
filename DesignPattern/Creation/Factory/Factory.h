#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Product.h"
#include <memory>

//工厂基类 与 Product基类相对应
class Factory
{
public:
  virtual ~Factory() {}
  virtual std::unique_ptr<Product> CreateProduct() = 0;
};

//具体工厂  与  具体产品相对应
class ConcreteFactory :public Factory
{
public:
  std::unique_ptr<Product> CreateProduct() {
    return std::make_unique<ConcreteProduct>();
  }
};

/*
工厂模式的作用：
1.提供创建对象的接口
2.将对象的实例化延迟到子类中实现

要解决的问题：
1.一个基类指针指向子类对象，基类存在许多子类，创建子类时需要知道实际子类名称才能进行new
2.在一个类A中使用B, AB均为抽象基类, 如果需要A来创建B的子类对象，
  那么就不知道该创建什么对象，这时可以传入工厂对象来创建
  如果不需要直接创建的话，也可直接传入B的子类对象。

情况1：
每个Product基类对应一种Factory,在Factory中实现所有具体Product的创建函数。
缺点：Factory类永远不可能封闭

情况2：
每个Product基类对应一种Factory,每个具体Product对应一个具体Factory。
由具体Factory创建具体Product。
缺点：以多态的方式，以添加一个子类的方式实现封闭。

讨论：参数化工厂,模板工厂
*/




#endif //~_FACTORY_H