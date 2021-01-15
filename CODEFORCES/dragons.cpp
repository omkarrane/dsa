#include <bits/stdc++.h>

using namespace std;

int main()
{
  int s, n;
  cin >> s >> n;

  int d[10001] = {0};
  int m = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    d[tmp1] += tmp2;
    if (m < tmp1)
      m = tmp1;
  }

  bool flag = false;
  for (int i = 0; i <= m; i++)
  {
    if (s > i)
      s += d[i];
    else
    {
      flag = true;
      break;
    }
  }

  if (flag)
    cout << "NO\n";
  else
    cout << "YES\n";

  return 0;
}