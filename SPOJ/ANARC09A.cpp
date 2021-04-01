#include <bits/stdc++.h>
using namespace std;

/**
 * can use 2 simple variables, one to store open brackets and one to store answer
 * for every open bracket increment open variable
 * for closing bracket, if open is already 0, means an invalid string is found, then increment result and open variable as we will be converting this to open one, else decrement open
 * once done, check the number of open brackets, we need to add half of that to result variable for converting to valid string
 */
int main()
{
  string s;
  int j = 1;
  while (cin >> s)
  {
    if (s[0] == '-')
      break;
    int open = 0;
    int n = s.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == '{')
        open++;
      else
      {
        if (open == 0)
        {
          open++;
          res++;
        }
        else
        {
          open--;
        }
      }
    }
    res += open / 2;
    if (open & 1)
      res++;

    cout << j++ << ". " << res << "\n";
  }

  return 0;
}