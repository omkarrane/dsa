#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> m >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  int min = INT_MAX;
  for (int i = 0; i <= (n - m); i++)
  {
    if ((arr[i + m - 1] - arr[i]) < min)
      min = arr[i + m - 1] - arr[i];
  }

  cout << min << endl;

  return 0;
}