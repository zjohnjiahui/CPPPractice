#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct Base {
  virtual void bar() { std::cout << "B::bar\n"; }
  virtual ~Base() = default;//虚析构，保证unique_ptr<Base>保有一个Derived指针时正确释放
};
struct Derived : Base
{
  Derived() { std::cout << "D::D\n"; }
  ~Derived() { std::cout << "D::~D\n"; }
  void bar() override { std::cout << "D::bar\n"; }
};

// 删除器两种形式
// 函数 或 仿函数operator()

struct BaseDeleter
{
  void operator() (Base* p) {
    std::cout << "Calling delete for Base object... \n";
    delete p;
  }
};
struct DerivedDeleter
{
  void operator() (Derived* p) {
    std::cout << "Calling delete for Derived object... \n";
    delete p;
  }
};

// 文件指针的删除器, 函数形式
void close_file(std::FILE* fp) { std::fclose(fp); }

// 以值或以右值引用接收它, 发生资源转移
std::unique_ptr<Derived> pass_through(std::unique_ptr<Derived> p)
{
  p->bar();
  return p;
}
// 使用引用传递，还是原来的指针，不发生资源转移
void pass_ref(std::unique_ptr<Derived>& p)
{
  p->bar();
}

int main()
{
  std::cout << "unique ownership semantics demo\n";
  {
    auto p = std::make_unique<Derived>(); // p 是占有 D 的 unique_ptr
    auto q = pass_through(std::move(p));
    assert(!p); // 现在 p 不占有任何内容并保有空指针
    
    q->bar();   // 而 q 占有 D 对象
    pass_ref(q);
    assert(q); //q仍然有资源
  } // ~D 调用于此

  std::cout << "Runtime polymorphism demo\n";
  {
    std::unique_ptr<Base> p = std::make_unique<Derived>(); // p 是占有 D 的 unique_ptr
                                                  // 作为指向基类的指针
    p->bar(); // 虚派发

    std::vector<std::unique_ptr<Base>> v;  // unique_ptr 能存储于容器
    v.push_back(std::make_unique<Derived>());
    v.push_back(std::move(p));
    v.emplace_back(new Derived);
    for (auto& p : v) p->bar(); // 虚派发
  } // ~D called 3 times

  std::cout << "Custom deleter demo\n";
  std::ofstream("demo.txt") << 'x'; // 准备要读的文件
  {
    std::unique_ptr<std::FILE, void(*)(std::FILE*) > fp(std::fopen("demo.txt", "r"),
      close_file);
    if (fp) // fopen 可以打开失败；该情况下 fp 保有空指针
      std::cout << (char)std::fgetc(fp.get()) << '\n';
  } // fclose() 调用于此，但仅若 FILE* 不是空指针（即 fopen 成功）

  std::cout << "Custom lambda-expression deleter demo\n";
  {
    std::unique_ptr<Derived, std::function<void(Derived*)>> p(new Derived, [](Derived* ptr)
      {
        std::cout << "destroying from a custom deleter...\n";
        delete ptr;
      });  // p 占有 D
    p->bar();
  } // 调用上述 lambda 并销毁 D

  // unique_ptr存储数组资源
  std::cout << "Array form of unique_ptr demo\n";
  {
    std::unique_ptr<Derived[]> p{ new Derived[3] };
  } // 调用 ~D 3 次

  // release: 返还资源，变为nullptr
  std::cout << "Release unique_ptr demo\n";
  {
    std::cout << "Creating new Foo...\n";
    std::unique_ptr<Base> up(new Base());

    std::cout << "About to release Foo...\n";
    Base* fp = up.release();// release后返还原指针，变为nullptr

    assert(up.get() == nullptr);
    std::cout << "Foo is no longer owned by unique_ptr...\n";

    delete fp;
  }

  // reset: 原来的被删除,替换为新的
  std::cout << "Reset unique_ptr demo\n";
  {
    std::cout << "Creating new Foo...\n";
    std::unique_ptr<Base, BaseDeleter> up(new Base(), BaseDeleter());  // up 占有 Foo 指针（删除器 D ）

    std::cout << "Replace owned Foo with a new Foo...\n";
    up.reset(new Base());  // 调用旧者的删除器,原来的被删除,替换为新的

    std::cout << "Release and delete the owned Foo...\n";
    up.reset(nullptr);
  }

  // swap: 两个指针的资源互换
  std::cout << "Swap unique_ptr demo\n";
  {
    std::unique_ptr<Base> up1(new Base());
    std::unique_ptr<Base> up2(new Base());

    up1.swap(up2);
  }

}
