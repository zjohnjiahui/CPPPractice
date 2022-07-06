#include <vector>

int binarySearch(std::vector<int>& nums, int target)
{
  if (nums.size == 0)
    return -1;

  int left = 0;
  int right = nums.size()-1;

  //搜索区间 [left,right] 决定了新区间是[left,middle-1]或[middle+1,right]
  while (left <= right)//停止条件 //left > right
  {
    int middle = (left + right) / 2;
    if (nums[middle] == target)
    {
      return middle;
    }
    else if (nums[middle] > target)
    {
      right = middle - 1;
    }
    else if (nums[middle] < target)
    {
      left = middle + 1;
    }
  }
  return -1;
}

int binarySearchLeft(std::vector<int>& nums, int target)
{
  if (nums.size == 0)
    return -1;

  int left = 0;
  int right = nums.size();

  //搜索区间 [left,right) 决定了新区间是[left,middle)或[middle+1,right)
  while (left < right)//停止条件 left == right
  {
    int middle = (left + right) / 2;
    if (nums[middle] == target)
    {
      right = middle;//向左收紧区间
    }
    else if (nums[middle] < target)
    {
      left = middle + 1;
    }
    else if (nums[middle] > target)
    {
      right = middle;
    }
  }

  return left;
}

int binarySearchRight(std::vector<int>& nums, int target)
{
  if (nums.size == 0)
    return -1;

  int left = 0;
  int right = nums.size();

  //搜索区间 [left,right) 决定了新区间是[left,middle)或[middle+1,right)
  while (left < right)//停止条件 left == right
  {
    int middle = (left + right) / 2;
    if (nums[middle] == target)
    {
      left = middle + 1;//向右收紧区间
    }
    else if (nums[middle] < target)
    {
      left = middle + 1;
    }
    else if (nums[middle] > target)
    {
      right = middle;
    }
  }

  return left -1;
}
