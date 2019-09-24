#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    long long int n, temp;
    cin >> n;

    for(int i = 0; i < n; i++)
      cin >> temp;

    long long int res = n * (n - 1) / 2;

    cout << res << endl;
  }

  return 0;
}