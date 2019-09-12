#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;


  int c = 0, h = 0, e = 0, f = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == 'C')
      c++;
    else if(s[i] == 'H')
    {
      h++;
      if(h >= c)
        h = c;
    }
    else if(s[i] == 'E')
    {
      e++;
      if(e >= h)
        e = h;
    }
    else
    {
      f++;
      if(f >= e)
        f = e;
    }
  }

  cout << f << endl;

  return 0;
}