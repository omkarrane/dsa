#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  stack<char> st;
  for (int i = 0; i < s.size(); i++)
  {
    if (!st.empty() && st.top() == s[i])
      st.pop();
    else
      st.push(s[i]);
  }

  if (st.empty())
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}