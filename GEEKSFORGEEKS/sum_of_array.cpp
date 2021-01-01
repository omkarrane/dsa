#include <bits/stdc++.h>

using namespace std;

int sum_of_array(int *, int, int, int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << sum_of_array(arr, n, 0, 0) << "\n";
  return 0;
}

int sum_of_array(int arr[], int n, int i, int sum)
{
  if (i == n)
    return 0;

  sum =+ arr[i];
  return sum + sum_of_array(arr, n, ++i, sum);
}