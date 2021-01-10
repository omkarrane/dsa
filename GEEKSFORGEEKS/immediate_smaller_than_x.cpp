#include <bits/stdc++.h>
using namespace std;

int immediate_smaller_than_x(int[], int, int);

int main()
{
  int n, x;
  cin >> n >> x;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << immediate_smaller_than_x(arr, n, x) << "\n";
  return 0;
}

int immediate_smaller_than_x(int arr[], int n, int x)
{
  sort(arr, arr + n);
  int low = 0;
  int high = n - 1;
  int res = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] < x)
    {
      low = mid + 1;
      res = arr[mid];
    }
    else
      high = mid - 1;
  }

  return res;
}
