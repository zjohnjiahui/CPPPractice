#include <limits>

// refer:
//  https://blog.csdn.net/fengbingchun/article/details/77922558
//  https://cplusplus.com/reference/limits/numeric_limits/

int main()
{
  // min: minimum
  // max: maximum
  // lowest c++11: 
  //    For integral types: the same as min().
  //    For floating types: generally, the negative of max()
  // digits:
  //    For integer types: number of non-sign bits
  //    For floating types: number of digits

  std::cout << std::numeric_limits<int>::min() << std::endl;
  std::cout << std::numeric_limits<int>::max() << std::endl;
  std::cout << std::numeric_limits<int>::lowest() << std::endl;
  std::cout << std::numeric_limits<int>::digits << std::endl;

  std::cout << std::numeric_limits<float>::min() << std::endl;
  std::cout << std::numeric_limits<float>::max() << std::endl;
  std::cout << std::numeric_limits<float>::lowest() << std::endl;
  std::cout << std::numeric_limits<float>::digits << std::endl;

  return 0;
}
