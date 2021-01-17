#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;

  bool flag = true;
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      string s(m, '#');
      cout << s << "\n";
    }
    else if (flag)
    {
      string s(m - 1, '.');
      cout << s << "#\n"; 
      flag = !flag;
    }
    else
    {
      string s(m - 1, '.');
      cout << "#" << s << "\n"; 
      flag = !flag;
    }
  }

  return 0;
}