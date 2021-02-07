#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n;
  cin >> n;
  int e, count = 0, odd = 0, even = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> e;
    if (e % 2 == 0)
      even++;
    else
      odd++;
    if (i % 2 != e % 2)
      count++;
  }

  if (count % 2 != 0)
  {
    cout << "-1\n";
    return;
  }
  
  if (n % 2 == 0 && odd != even)
  {
    cout << "-1\n";
    return;
  }
  else if (n % 2 == 1 && even != (odd + 1))
  {
    cout << "-1\n";
    return;
  }

  cout << count / 2 << "\n";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}