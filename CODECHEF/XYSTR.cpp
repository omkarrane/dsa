#include <bits/stdc++.h>
using namespace std;

bool ispair(char &a, char &b)
{
  if (a == 'y' && b == 'x')
    return true;

  if (a == 'x' && b == 'y')
    return true;

  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> dp(n, 0);

    if (n <= 1)
    {
      cout << "0\n";
    }
    else
    {
      if (ispair(s[0], s[1]))
      {
        dp[1] = 1;
      }

      for (int i = 2; i < n; i++)
      {
        if (ispair(s[i], s[i - 1]))
          dp[i] = max(dp[i - 1], dp[i - 2] + 1);
        else
          dp[i] = max(dp[i - 1], dp[i - 2]);
      }

      cout << dp[n - 1] << "\n";
    }
  }

  return 0;
}