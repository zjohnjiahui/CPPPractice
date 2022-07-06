#include "Obj.h"

//https://mp.weixin.qq.com/s/LwnDtK6HNZo_StIxQ5yJhA
/*
函数返回的方式：
  1.通过寄存器返回 (内置类型)
  2.通过栈返回 (结构体和类)

通过栈返回时会发生拷贝构造，这个文章搞清楚了 函数返回时发生的拷贝次数和RVO(NRVO)优化
*/

/*
  Obj fun() // RVO时最优
  {
    return Obj();
  }

  Obj fun() // NRVO时最优，使用RVO时多一次拷贝构造
  {
    Obj obj;
    return obj;
  }

  变为

  void fun(Obj &_obj) {
    _obj.Obj::Obj();
  }

*/


/* 
  发生RVO
  RVO优化原理：将 值返回 变为 参数引用，临时对象的地址 赋给 引用参数
  在return时优化, 优化临时对象
*/
Obj func_return()
{
  return Obj();
}

/*
  发生NRVO
  NRVO优化原理：将 值返回 变为 参数引用，对引用参数直接构造
  在构造时优化，优化local对象
*/
Obj func_named_return() 
{
  Obj obj;
  return obj;
}

/*
  优化失效：
  # 1.有运行时依赖，多分支出口。如果单出口，仅返回时机不同仍可以优化
  2.返回全局变量
  3.返回函数参数
  4.返回成员变量
  # 5.调用函数(main)使用拷贝赋值(operator=) 多一次移动赋值
  # 6.返回std::move() 多一次移动构造
*/


// N(RVO)失效
Obj func_move()
{
  Obj tmp;
  return std::move(tmp); //具名对象转化为右值,导致使用RVO优化,与NRVO相比多一次移动构造
}

int main()
{
  /*
  无优化时：

  调用构造函数，生成Local对象
  调用拷贝构造函数，生成Stack临时对象
  调用析构函数，析构第1步生成的Local对象
  调用拷贝构造函数，将第2步生成的Stack临时变量拷贝到main()函数中的obj对象中
  调用析构函数，析构第2步生成的Stack临时对象
  调用析构函数，析构main()函数中的obj对象

  发生1次构造和2次拷贝3次析构
  */

  Obj o1 = func_named_return();
  /*
  func_named_return():
  Obj() 000000FD55B5FD48  //只发生了一次构造
  ~Obj() 000000FD55B5FD48

  经过优化后，取消了2次拷贝.发生1次构造1次析构
  RVO 和 NRVO 的效果相同，原理相似，略有不同

  */

  Obj o2 = func_return();
  
  Obj o3 = func_move();

  Obj o4;
  o4 = func_named_return();
  
  return 0;
}
