#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  int arr[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < k; i++)
  {
    int x;
    cin >> x;

    int l = 0;
    int r = n - 1;
    bool flag = false;
    while (l <= r)
    {
      int m = (l + r) / 2;
      if (arr[m] == x)
      {
        flag = true;
        break;
      }
      else if (x < arr[m])
        r = m - 1;
      else if (x > arr[m])
        l = m + 1;
    }

    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}