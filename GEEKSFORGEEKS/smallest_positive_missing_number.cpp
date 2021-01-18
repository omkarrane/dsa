#include <bits/stdc++.h>
using namespace std;

int missing_positive(int[], int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << missing_positive(arr, n) << "\n";
  return 0;
}

int missing_positive(int arr[], int n)
{
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
      swap(arr[j++], arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > 0 && arr[abs(arr[i])] > 0)
      arr[abs(arr[i])] = -arr[abs(arr[i])];
  }
}
