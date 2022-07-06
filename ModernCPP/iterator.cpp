#include <array>

int main()
{
  std::array<int, 5> arr = { 0,1,2,3,4 };

  /*迭代器
  iterator 可遍历，可改变所指元素
  const_iterator 可遍历，不可改变所指元素
  const iterator 不可遍历，可改变所指元素*/

  // const_iterator 只能读取
  std::array<int, 5>::const_iterator it0 = arr.cbegin();
  temp_element = *it0;

  // iterator 可读可写
  std::array<int, 5>::iterator it1 = arr.end() - 1;
  temp_element = *it1;
  *it1 *= 1;

  // const_reverse_iterator 常量反向迭代器
  std::array<int, 5>::const_reverse_iterator it2 = arr.crbegin();
  temp_element = *it2; 

  // reverse_iterator 反向迭代器
  std::array<int, 5>::reverse_iterator it3 = arr.rend() - 1;
  temp_element = *it3;
  *it1 *= 1;

  return 0;
}
