#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int n;
  s_int(n);

  string s;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    if (s.size() > 10)
    {
      char first = s.at(0);
      char last = s.at(s.size() - 1);
      cout << first << s.size() - 2 << last << "\n";
    }
    else
      cout << s << "\n";
  }

  return 0;
}