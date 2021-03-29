#include <bits/stdc++.h>
using namespace std;

/**
 * we can use a stack<pair> to solve this question
 * when a "for" occurs, push a {x, 0} to the stack
 * when a add occurs, if it occurs inside a for, then increment stack.top().second by 1, else increment the result by 1
 * when a end occurs, if stack.size() is 1 before popping then add stack.top() to result, else update the next stack.top()
 */
int main()
{
  int t;
  cin >> t;
  unsigned long long num = 0;
  stack<pair<unsigned long long, unsigned long long>> st;
  bool flag = false, flag2 = false;;
  unsigned long long overflow = pow(2ll, 32ll) - 1ll;
  while (t--)
  {
    string s;
    cin >> s;
    if (s == "add")
    {
      flag = true;
      if (st.empty())
        num++;
      else
        st.top().second++;
    }
    else if (s == "for")
    {
      unsigned long long f;
      cin >> f;
      st.push({f, 0});
    }
    else if (s == "end")
    {
      if (st.size() == 1)
      {
        pair<unsigned long long, unsigned long long> temp = st.top();
        st.pop();
        num += (temp.second * temp.first * 1ll);
        if (num > overflow)
          flag2 = false;
      }
      else
      {
        pair<unsigned long long, unsigned long long> temp = st.top();
        st.pop();
        st.top().second += (temp.second * temp.first * 1ll);
        if (st.top().second > overflow)
          flag2 = true;
      }
    }
  }

  if (num < 0 || num > overflow || (flag && num == 0) || flag2)
    cout << "OVERFLOW!!!\n";
  else
    cout << num << "\n";

  return 0;
}