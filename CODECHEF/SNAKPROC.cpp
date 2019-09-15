#include <bits/stdc++.h>

using namespace std;

int main()
{
  int r;
  cin >> r;

  while (r--)
  {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool found = true, res = true;
    for(int i = 0; i < n; i++)
    {
      if(s[i] == 'H')
      {
        if(!found)
        {
          res = false;
          break;
        }
        
        found = false;
      }
      else if(s[i] == 'T')
      {
        if(found)
        {
          res = false;
          break;
        }

        found = true;
      }
    }

    if(res && found)
      cout << "Valid" << endl;
    else
      cout << "Invalid" << endl;
  }
}