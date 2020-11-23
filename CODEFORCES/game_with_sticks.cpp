#include <bits/stdc++.h>

using namespace std;

int main()
{
  int m, n;
  cin >> m >> n;

  int p = m;
  if (m > n)
    p = n;

  if (p % 2 == 0)
    cout << "Malvika\n";
  else
    cout << "Akshat\n";

  return 0;
}