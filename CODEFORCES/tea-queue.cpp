#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    vector<int> ans;
    int n;
    cin >> n;
    int wait = 1;
    int start, end;
    cin >> start >> end;
    ans.push_back(start);
    int last = ans[0];
    for (int i = 1; i < n; i++)
    {
      cin >> start >> end;
      if (last + 1 > end)
      {
        ans.push_back(0);
        continue;
      }

      if (last < start)
        ans.push_back(start);
      else
        ans.push_back(last + 1);
      last = ans[i];
    }

    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << "\n";
  }

  return 0;
}