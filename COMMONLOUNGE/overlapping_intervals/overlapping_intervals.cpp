#include<bits/stdc++.h>

#define s_int(num) scanf("%d", &num)
#define s_char(c) scanf("%c", &c)

using namespace std;
void solve();
void quick_sort(int[], int[], int, int);
int partition(int[], int[], int, int);

int partition(int arr1[], int arr2[], int low, int high)
{
  int pivot = arr1[high];
  int i = low - 1;
  int j = low;
  for (j = low; j < high; j++)
  {
    if (arr1[j] <= pivot)
    {
      i++;
      int temp = arr1[i];
      arr1[i] = arr1[j];
      arr1[j] = temp;

      temp = arr2[i];
      arr2[i] = arr2[j];
      arr2[j] = temp;
    }
  }

  i++;
  int temp = arr1[high];
  arr1[high] = arr1[i];
  arr1[i] = temp;

  temp = arr2[high];
  arr2[high] = arr2[i];
  arr2[i] = temp;
  return i;
}

void quick_sort(int arr1[], int arr2[], int low, int high)
{
  if (low >= high) return;
  int partition_index = partition(arr1, arr2, low, high); 
  quick_sort(arr1, arr2, low, (partition_index - 1));
  quick_sort(arr1, arr2, (partition_index + 1), high);
}

void solve()
{
  int n;
  s_int(n);
  int arr1[n], arr2[n];
  char c;
  for (int i = 0; i < n; i++)
  {
    s_int(arr1[i]);
    s_int(arr2[i]);
    s_char(c);
  }
  quick_sort(arr1, arr2, 0, n - 1);

  for (int i = 1; i < n; i++)
  {
    if (arr1[i - 1] == arr1[i] || arr2[i - 1] >= arr1[i])
    {
      printf("YES\n");
      return;
    }
  }
  printf("NO\n");
}

int main()
{
  int t;
  s_int(t);
  while(t--)
  {
    solve();
  }
}