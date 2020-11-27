#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  if ((a * m) <= b)
    cout << a * n << endl;
  else
  {
    int q;
    if (n % m == 0)
      q = (n / m) * b;
    else
      q = min({(((n / m) * b) + (n % m) * a), ((n / m) + 1) * b});

    cout << q << endl;
  }

  return 0;
}