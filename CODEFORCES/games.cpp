#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  pair<int, int> p[n];
  for (int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;

  int res = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i != j && p[i].first == p[j].second)
        res++;
    }
  }

  cout << res << endl;

  return 0;
}