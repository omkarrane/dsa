#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  stack<pair<int, int>> st;
  while (t--)
  {
    string s;
    cin >> s;
    if (s == "PUSH")
    {
      int temp;
      cin >> temp;
      if (st.empty())
        st.push({temp, temp});
      else
      {
        if (st.top().second < temp)
          st.push({temp, st.top().second});
        else
          st.push({temp, temp});
      }
    }
    else if (s == "POP")
    {
      if (st.empty())
      {
        cout << "EMPTY\n";
      }
      else
      {
        st.pop();
      }
    }
    else if (s == "MIN")
    {
      if (st.empty())
        cout << "EMPTY\n";
      else
        cout << st.top().second << "\n";
    }
  }

  return 0;
}