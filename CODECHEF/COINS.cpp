#include <bits/stdc++.h>
#define lli long long int

using namespace std;
unordered_map<lli, lli> l;

lli solve(lli n)
{
  if (n < 4)
    return n;

  if (n > (n / 4) + (n / 3) + (n / 2))
    return n;

  if (l.count(n))
    return l[n];

  return l[n] = solve(n / 4) + solve(n / 3) + solve(n / 2);
}

int main()
{
  lli n;
  while (cin >> n)
  {
    lli i = solve(n);
    printf("%lld\n", i);
  }
}