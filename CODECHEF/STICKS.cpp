#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    int temp, hash[1001] = {0};

    for(int i = 0; i < n; i++)
    {
      cin >> temp;
      hash[temp]++;
    }

    int a = 0, b = 0;
    for(int i = 1000; i > 0; i--)
    {
      if(hash[i] > 1)
      {
        if(hash[i] >= 4)
        {
          if(a == 0 && b == 0)
          {
            a = i;
            b = i;
            break;
          }
          else if(a == 0)
            a = i;
          else if(b == 0)
          {
            b = i;
            break;
          }
        }

        if(hash[i] >= 2)
        {
          if(a != 0)
          {
            b = i;
            break;
          }
          else
            a = i;
        }
      }
    }

    if(a == 0 || b == 0)
      cout << "-1" << endl;
    else
      cout << (a * b) << endl;
  }

  return 0;
}