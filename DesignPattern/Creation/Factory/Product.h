#ifndef _PRODUCT_H_
#define _PRODUCT_H_
#include <iostream>

class Product
{
public:
  virtual ~Product() {};
};

class ConcreteProduct :public Product
{
public:
  ~ConcreteProduct() {}
  ConcreteProduct(){
    std::cout << "ConcreteProduct" << std::endl;
  }
};

/*虚函数后面加 = 0，表示这个函数为纯虚函数，纯虚函数的一般形式：virtual 函数类型 函数名(参数表列) = 0;
特点：
1.纯虚函数没有函数体；
2.一个类里如果包含 ＝0 的纯虚函数，那么这个类就是一个抽象类
3.抽象类不能具体实例化（不能创建它的对象），而只能由它去派生子类
4.在派生类中对此函数提供定义后，它才能具备函数的功能，可被调用。*/

/*
基类析构函数声明为纯虚函数：基类的指针指向派生类对象，为了让用基类的指针正确删除派生类对象。

正常情况下:基类指针可以指向派生类的对象（多态性），如果删除该指针delete p；
  就会调用该指针指向的派生类析构函数，而派生类的析构函数又自动调用基类的析构函数，
  这样整个派生类的对象完全被释放

如果析构函数不被声明成虚函数:则编译器实施静态绑定，在删除基类指针时，
  只会调用基类的析构函数而不调用派生类析构函数，这样就会造成派生类对象析构不完全。

总结：
1.如果某个类不包含虚函数，那一般是表示它将不作为一个基类来使用
2.无故的声明虚析构函数和永远不去声明一样是错误的
3.当且仅当类里包含至少一个虚函数的时候才去声明虚析构函数

*/


#endif //~_PRODUCT_H