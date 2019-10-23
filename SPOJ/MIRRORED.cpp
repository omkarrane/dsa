#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cout << "Ready\n";
  while(getline(cin, s))
  {
    if(s[0] == 'd')
    {
      if(s[1] == 'b')
      {
        cout << "Mirrored pair\n";
        continue;
      }
    }
    else if(s[0] == 'b')
    {
      if(s[1] == 'd')
      {
        cout << "Mirrored pair\n";
        continue;
      }
    }
    else if(s[0] == 'q')
    {
      if(s[1] == 'p')
      {
        cout << "Mirrored pair\n";
        continue;
      }
    }
    else if(s[0] == 'p')
    {
      if(s[1] == 'q')
      {
        cout << "Mirrored pair\n";
        continue;
      }
    }
    else if(isspace(s[0]) && isspace(s[1]))
      break;
    else
    {
      cout << "Ordinary pair\n";
      continue;
    }
    cout << "Ordinary pair\n";
  }

  return 0;
}