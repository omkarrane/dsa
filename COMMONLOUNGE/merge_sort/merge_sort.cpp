#include <bits/stdc++.h>
#define s_int(num) scanf("%d", &num)

using namespace std;

void merge(int arr[], int low, int mid, int high)
{
  int a_len = mid - low + 1;
  int b_len = high - mid;

  int arr_a[a_len], arr_b[b_len];
  for (int i = 0; i < a_len; i++)
    arr_a[i] = arr[low + i];

  for (int i = 0; i < b_len; i++)
    arr_b[i] = arr[mid + i + 1];

  int i = 0, j = 0, k = low;
  while (i < a_len && j < b_len)
  {
    if (arr_a[i] < arr_b[j])
      arr[k++] = arr_a[i++];
    else
      arr[k++] = arr_b[j++];
  }

  while (i < a_len)
    arr[k++] = arr_a[i++];

  while (j < b_len)
    arr[k++] = arr_b[j++];
}

void merge_sort(int arr[], int low, int high)
{
  if (low == high)
    return;

  int mid = (low + high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

void solve()
{
  int n;
  s_int(n);
  int arr[n];
  for (int i = 0; i < n; i++)
    s_int(arr[i]);

  merge_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

int main()
{
  int t;
  s_int(t);
  while (t--)
  {
    solve();
  }
  return 0;
}