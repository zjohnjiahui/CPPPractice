#include <iostream>

//refer:
// https://blog.csdn.net/jlusuoya/article/details/77331914
// https://interviewguide.cn/notes/03-hunting_job/02-interview/01-01-01-%E5%9F%BA%E7%A1%80%E8%AF%AD%E6%B3%95.html

// 定义：结构体成员根据一定内存大小进行对齐，
//      当前对齐内存块不足以容纳下一个成员时
//      从下一个对齐内存块开始
// 默认对齐大小：结构体成员的最大内存大小
// 指令： alignas(n) 或 #pragma pack

// alignas 失效的情况
// 1.对齐值不是2^N次方
// 2.对齐值小于默认对齐值(结构体成员的最大内存大小)

void test_alignas()
{
  struct Info0 {
    uint8_t a;
    uint32_t b;
    uint8_t c;
  };
  /*
  0---1---4---8---9--12
  | a |pad| b | c |pad|
  */

  std::cout << sizeof(Info0) << std::endl;   // 12  4 + 4 + 4
  std::cout << alignof(Info0) << std::endl;  // 4

  struct Info1 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
  };
  /*
  0---1---2---4---5---6
  | a |pad| b | c |pad|
  */

  std::cout << sizeof(Info1) << std::endl;   // 6  2 + 2 + 2
  std::cout << alignof(Info1) << std::endl;  // 2

  struct alignas(4) Info2 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
  };
  /*
  在align块内部仍会进行对齐，以align块内部的最大成员进行对齐
  0---1---2---4---5---8
  | a |pad| b | c |pad|
  */

  std::cout << sizeof(Info2) << std::endl;   // 8  4 + 4
  std::cout << alignof(Info2) << std::endl;  // 4
  std::cout << offsetof(Info2, a) << std::endl; // 0
  std::cout << offsetof(Info2, b) << std::endl; // 2
  std::cout << offsetof(Info2, c) << std::endl; // 4

  return;
}


int test_onebyte()
{
  // 由于alignas不能小于默认对齐字节
  // 只能通过pragma pack进行1字节对齐
  // 这样能够节省内存，但降低了读取效率
  // cpu是按照内存块读取的，这使得cpu每次读取的内存降低了
  
#if defined(__GNUC__) || defined(__GNUG__)
  #define ONEBYTE_ALIGN __attribute__((packed))
#elif defined(_MSC_VER)
  #define ONEBYTE_ALIGN
  #pragma pack(push,1)
#endif

  struct Info_OneByte {
    uint8_t a;
    uint32_t b;
    uint8_t c;
  } ONEBYTE_ALIGN;

#if defined(__GNUC__) || defined(__GNUG__)
  #undef ONEBYTE_ALIGN
#elif defined(_MSC_VER)
  #pragma pack(pop)
  #undef ONEBYTE_ALIGN
#endif

  std::cout << sizeof(Info_OneByte) << std::endl;   // 6 1 + 4 + 1
  std::cout << alignof(Info_OneByte) << std::endl;  // 6

  return 0;
}
