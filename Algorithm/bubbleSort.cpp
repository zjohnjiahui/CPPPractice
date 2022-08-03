void bubbleSort(std::vector<int>& arr)
{
  for (int i = 0; i < arr.size()-1; ++i)
  {
    bool isSort = true;
    for (int j = 0; j < arr.size()-1-i; ++j)
    {
      if (arr[j] > arr[j + 1])
      {
        isSort = false;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
    if (isSort)
      break;
  }
}
