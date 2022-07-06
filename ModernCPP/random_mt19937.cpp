#include <random>
#include <iostream>

int main()
{
  int n = 10;
  std::mt19937 gen{ std::random_device{}() };
  std::uniform_int_distribution<int> int_dis(0, n - 1);
  std::normal_distribution<float> norm_dis(0, 1);
  
  std::cout << "uniform_int_distribution: ";
  for (int i = 0; i < 10; ++i)
  {
    std::cout << int_dis(gen) << " ";
  }
  std::cout << std::endl;

  std::cout << "normal_distribution: ";
  for (int i = 0; i < 10; ++i)
  {
    std::cout << norm_dis(gen) << " ";
  }
  std::cout << std::endl;
  reutrn 0;
}
