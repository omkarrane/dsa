#include <bits/stdc++.h>

using namespace std;

int main()
{
  stack<int> s1, s2;
  int q, type, elem;
  cin >> q;

  while (q--)
  {
    cin >> type;

    if (type == 1)
    {
      cin >> elem;

      s1.push(elem);
    }
    else
    {
      if(s2.empty())
      {
        while(!s1.empty())
        {
          s2.push(s1.top());
          s1.pop();
        }
      }

      if(type == 2)
        s2.pop();
      else
        cout << s2.top() << endl;
    }
  }

  return 0;
}