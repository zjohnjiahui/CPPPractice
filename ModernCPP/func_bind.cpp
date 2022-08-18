#include <iostream>
#include <map>
#include <string>

// 普通函数
void func(int a, std::string s, std::map<int, int> m)
{
  std::cout << a << std::endl;
  std::cout << s.size() << std::endl;
  m[0] = 0;
  std::cout << m[0] << std::endl;
}

// 成员函数
class Foo1
{
public:
  void func(int a) { std::cout << a << std::endl; }

  // 原函数为 void(int), 经过参数绑定后变为了 void(void)
  std::function<void(void)> getFunc(int num) {
    return std::bind(&Foo1::func, this, num);
  }
};


int main() {

  auto f0 = std::bind(&func, 10, std::string("abc"), std::map<int,int>());
  f0();

  // 占位符std::placeholders::_2表示 
  // 调用函数的时候它的第2个输入参数(调用时的顺序) 即10
  // 和 它放置在原型处的参数匹配 即 int
  // 简记： std::placeholders::_x, 在第x个参数 输入 占位处的类型
  auto f1 = std::bind(&func, std::placeholders::_2, std::placeholders::_3, std::placeholders::_1);
  f1(std::map<int, int>(), 10, std::string("abc"));

  Foo1 tempF1;
  auto f2 = std::bind(&Foo1::func, tempF1, 13);
  auto f3 = tempF1.getFunc(10);
  f2();
  f3();
}
