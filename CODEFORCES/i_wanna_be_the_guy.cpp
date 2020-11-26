#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int p, q, temp, arr[n + 1];
  fill(arr, arr + n + 1, 0);

  cin >> p;

  for (int i = 0; i < p; i++)
  {
    cin >> temp;
    arr[temp]++;
  }

  cin >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> temp;
    arr[temp]++;
  }

  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (arr[i] == 0)
    {
      flag = false;
      break;
    }

  if (flag)
    cout << "I become the guy.\n";
  else
    cout << "Oh, my keyboard!\n";

  return 0;
}