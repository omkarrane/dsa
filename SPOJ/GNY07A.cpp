#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, d = 1;
  cin >> n;

  while(n--)
  {
    int m;
    string s;
    cin >> m >> s;

    cout << d++ << " " << s.erase(m - 1, 1) << endl;
  }

  return 0;
}