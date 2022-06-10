#pragma once

//refer: 
// https://www.cnblogs.com/sunchaothu/p/10389842.html 
// https://www.cnblogs.com/ltimaginea/p/15400066.html
// https://github.com/downdemo/Design-Patterns-in-Cpp17/blob/master/src/Singleton.cpp

// Magic static singleton (Mayer's singleton)
// blocked before initialization, thread safe

// key:
//   delete default copy/move constructor and operator=;
//   set constructor and destructor to private;
//   instance func return local static

// private destructor: 
//   heap only, can't be placed in stack ;
//   can't be deleted by 'delete' out of the class; Thus return pointer is ok.

class Singleton
{
public:
  Singleton(const Singleton&) = delete;
  Singleton(Singleton&&) = delete;
  Singleton& operator=(const Singleton&) = delete;
  Singleton& operator=(Singleton&&) = delete;

  static Singleton* Instance() {
    static Singleton instance;
    return &instance;
  }

private:
  Singleton() = default;
  ~Singleton() = default;
};
