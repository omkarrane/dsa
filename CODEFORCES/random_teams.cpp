#include <bits/stdc++.h>

#define lli long long int

using namespace std;

int main()
{
  lli n, m;
  cin >> n >> m;

  lli mi = 0;
  lli k = n / m;
  lli p = n % m;

  if (p == 0)
    mi = ((k * (k - 1)) / 2) * m;
  else
    mi = ((((k + 1) * k) / 2) * p) + (((k * (k - 1)) / 2) * (m - p));
  cout << mi << " ";
  mi = (n - m + 1) * (n - m) / 2;
  cout << mi << endl;

  return 0;  
}