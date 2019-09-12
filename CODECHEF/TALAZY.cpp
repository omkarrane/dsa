#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    long int n, b, m, cpy_n;
    cin >> n >> b >> m;
    cpy_n = n;

    long long int res = 0LL;

    while(n > 0)
    {
      if(cpy_n > 1 && cpy_n & 1)
        cpy_n++;

      if(cpy_n >> 1 == 0)
        res += m;
      else
        res += ((cpy_n >> 1) * m) + b;
      m <<= 1;
      if(cpy_n >> 1 == 0)
        n = 0;
      else
        n -= (cpy_n >> 1);
      cpy_n = n;
    }

    cout << res << endl;
  }

  return 0;
}