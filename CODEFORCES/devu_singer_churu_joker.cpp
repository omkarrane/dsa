#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, d;
  cin >> n >> d;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  sum += (10 * (n - 1));
  if (sum <= d)
  {
    int c = 2 * (n - 1);
    c += (d - sum) / 5;
    cout << c << "\n";
  }
  else
  {
    cout << "-1\n";
  }

  return 0;
}