#include <bits/stdc++.h>
using namespace std;

long long w, h, n;

bool good(long long x)
{
  return (x / w) * (x / h) >= n;
}

int main()
{
  cin >> w >> h >> n;

  long long l = 0, r = 1;
  while (!good(r))
    r *= 2;

  while (l < r - 1)
  {
    long long m = l + (r - l) / 2;
    if (good(m))
      r = m;
    else
      l = m;
  }

  cout << r << "\n";

  return 0;
}