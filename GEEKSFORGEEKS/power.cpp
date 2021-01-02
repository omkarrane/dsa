#include<bits/stdc++.h>

using namespace std;

int power(int, int);

int main()
{
  int n, p;
  cin >> n >> p;

  cout << power(n, p) << "\n";
  return 0;
}

int power(int n, int p)
{
  if (p == 0)
    return 1;
  else if (p < 0)
    return -1;
  else if (p == 1)
    return n;

  return n * power(n, --p);
}