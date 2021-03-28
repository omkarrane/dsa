#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  deque<int> d;
  bool toReverse = false;
  while (t--)
  {
    string s;
    int num;
    cin >> s;

    if (s == "toFront")
    {
      cin >> num;
      if (toReverse)
      {
        d.push_back(num);
      }
      else
      {
        d.push_front(num);
      }
    }
    else if (s == "push_back")
    {
      cin >> num;
      if (!toReverse)
      {
        d.push_back(num);
      }
      else
      {
        d.push_front(num);
      }
    }
    else if (s == "reverse")
    {
      if (d.empty())
        toReverse = false;
      else
        toReverse = !toReverse;
    }
    else if (s == "front")
    {
      if (d.empty())
      {
        cout << "No job for Ada?\n";
        continue;
      }

      if (!toReverse)
      {
        cout << d.front() << "\n";
        d.pop_front();
      }
      else
      {
        cout << d.back() << "\n";
        d.pop_back();
      }
    }
    else if (s == "back")
    {
      if (d.empty())
      {
        cout << "No job for Ada?\n";
        continue;
      }
      if (toReverse)
      {
        cout << d.front() << "\n";
        d.pop_front();
      }
      else
      {
        cout << d.back() << "\n";
        d.pop_back();
      }
    }
  }

  return 0;
}