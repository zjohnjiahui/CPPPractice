void merge(int* arr, int l, int q, int r)
{
  //有序数组的合并，[l,q] [q+1,r]
  int i, j, k;
  //array长度
  int n1 = q - l + 1;
  int n2 = r - q;

  //为两个数组申请临时空间
  int* L = new int[n1+1];
  int* R = new int[n2+1];

  //拷贝
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[q + j + 1];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  //比较 合并
  i = j = 0;
  for (k = l; k <= r; k++) {
    if (L[i] <= R[j])
      arr[k] = L[i++];
    else
      arr[k] = R[j++];
  }
  delete [] L;
  delete [] R;
}

void mergeSort(int* arr, int l, int r)
{
  if (r <= l)
    return;
  //分
  int q = l + (r - l) / 2;
  //治
  mergeSort(arr, l, q);
  mergeSort(arr, q + 1, r);
  //合并
  merge(arr, l, q, r);
}
