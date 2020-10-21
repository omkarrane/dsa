#include <bits/stdc++.h>
#define s_int(num) scanf("%d", &num)

using namespace std;

long long int merge(int arr[], int low, int mid, int high)
{
  int a_len = mid - low + 1;
  int b_len = high - mid;
  long long int inv = 0;

  int arr_a[a_len], arr_b[b_len];
  for (int i = 0; i < a_len; i++)
    arr_a[i] = arr[low + i];

  for (int i = 0; i < b_len; i++)
    arr_b[i] = arr[mid + i + 1];

  int i = 0, j = 0, k = low;
  while (i < a_len && j < b_len)
  {
    if (arr_a[i] <= arr_b[j])
      arr[k++] = arr_a[i++];
    else
    {
      inv += a_len - i;
      arr[k++] = arr_b[j++];
    }
  }

  while (i < a_len)
  {
    arr[k++] = arr_a[i++];
  }

  while (j < b_len)
  {
    arr[k++] = arr_b[j++];
  }

  return inv;
}

long long int merge_sort(int arr[], int low, int high)
{
  if (low == high)
    return 0;

  int mid = (low + high) / 2;
  long long int inv_a = merge_sort(arr, low, mid);
  long long int inv_b = merge_sort(arr, mid + 1, high);
  long long int inv_merge = merge(arr, low, mid, high);
  return inv_a + inv_b + inv_merge;
}

void solve()
{
  int n;
  s_int(n);
  int arr[n];
  for (int i = 0; i < n; i++)
    s_int(arr[i]);

  long long int res = merge_sort(arr, 0, n - 1);

  printf("%lld ", res);

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