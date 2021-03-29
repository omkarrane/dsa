#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * can use a simple variale to increment when a opening bracket arrives and decrement when a closing one arrives
 * when the variables value is below 0 means the substring is not a valid string
 * when the variables value is 0, it means the substring is a valid string, hence store the index in result
 */
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    int open = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '<')
        open++;
      else
        open--;

      if (open == 0)
        ans = i + 1;
      else if (open < 0)
        break;
    }

    cout << ans << "\n";
  }

  return 0;
}
