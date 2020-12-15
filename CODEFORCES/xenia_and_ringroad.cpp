#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, temp;
  cin >> n >> m;

  int curr = 1;
  long long int res = 0;
  for (int i = 0; i < m; i++)
  {
    cin >> temp;
    if (temp >= curr)
    {
      res += temp - curr;
      curr = temp;
    }
    else
    {
      res += (n - curr) + temp;
      curr = temp;
    }
  }

  cout << res << endl;
  return 0;
}