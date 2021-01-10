#include <bits/stdc++.h>
using namespace std;

int transition_point(int[], int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << transition_point(arr, n) << "\n";
  return 0;
}

int transition_point(int arr[], int n)
{
  int low = 0, high = n - 1;
  int res = -1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (arr[mid] == 1)
    {
      res = mid;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return res;
}
