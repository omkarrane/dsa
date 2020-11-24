#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  bool start = false;
  cin >> s;

  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
    {
      if (start)
      {
        cout << " ";
        start = false;
      }
      i += 2;
    }
    else
    {
      cout << s[i];
      start = true;
    }
  }

  cout << endl;
  return 0;
}