#include <bits/stdc++.h>
using namespace std;


/**
 * use a stack for storing every character and do the following operations
 * if current == stack.top() then pop
 * else push
 * collect the final output form stack and reverse it
 */
int main()
{
  string s;
  cin >> s;
  stack<char> st;
  int n = s.size();

  for (int i = 0; i < n; i++)
  {
    if (st.empty() || st.top() != s[i])
    {
      st.push(s[i]);
    }
    else
    {
      st.pop();
    }
  }

  string ans;
  while (!st.empty())
  {
    ans.push_back(st.top());
    st.pop();
  }

  reverse(ans.begin(), ans.end());
  cout << ans << "\n";

  return 0;
}