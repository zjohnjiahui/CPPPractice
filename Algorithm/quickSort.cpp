void quickSort(int* arr, int l, int r)
{
  //出口
  if (l >= r)
    return;
  int i = l;
  int j = r;
  
  // 枢轴点 分
  int pivot = arr[i];
  while (i < j)
  {
    //从后向前找比pivot小的
    while (arr[j] >= pivot && i < j)
      j--;
    arr[i] = arr[j];
    //从前往后找比pivot大的
    while (arr[i] <= pivot && i < j)
      i++;
    arr[j] = arr[i];
  }
  arr[i] = pivot;
  
  // 治
  quickSort(arr, l, i - 1);
  quickSort(arr, i + 1, r);
}
