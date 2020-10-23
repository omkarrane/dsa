#include <bits/stdc++.h>
#define s_int(num) scanf("%d", &num)

using namespace std;
void solve();
void quick_sort2(int[], int, int);
int quick_sort_partition(int[], int, int);



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

int quick_sort_partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  i++;
  int temp = arr[i];
  arr[i] = arr[high];
  arr[high] = temp;
  return i;
}

void quick_sort2(int arr[], int low, int high)
{
  if (low >= high)
    return;
  
  int partition_index = quick_sort_partition(arr, low, high);
  quick_sort2(arr, low, (partition_index - 1));
  quick_sort2(arr, (partition_index + 1), high);
}

void solve()
{
  int n;
  s_int(n);
  int arr[n];
  for (int i = 0; i < n; i++)
    s_int(arr[i]);

  quick_sort2(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}