#include <iostream>

int test_bit_field()
{

  struct Info {
    uint8_t a : 1;
    uint8_t b : 2;
    uint8_t c : 3;
    uint16_t  : 2; //无名成员不能使用，用于占位， 成员类型大小只要大于所需位数即可，整型只有有无符号的区别
    uint8_t e : 1;
    uint8_t pad : 7;
  };
  /**
  * 0 1   3     6   8 9            15
  * +-+---+-----+---+-+-------------+
  * | |   |     |   | |             |
  * |a| b |  c  | d |e|     pad     |
  * | |   |     |   | |             |
  * +-+---+-----+---+-+-------------+
  */

  Info info = {0};
  info.a = 0;
  info.b = 3;
  info.c = 9;// 9%8=1 超出表示范围会截断
  info.e = 1;

  std::cout << sizeof(Info) << std::endl;  //2
  std::cout << alignof(Info) << std::endl; //2 位域与字节对齐无关
  return 0;
}
