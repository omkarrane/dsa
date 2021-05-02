#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, w;
  cin >> n >> w;

  vector<int> items(n), wts(n);
  for (int i = 0; i < n; i++)
    cin >> wts[i] >> items[i];

  vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= w; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (wts[i - 1] <= j)
        dp[i][j] = max(dp[i][j], dp[i - 1][j - wts[i - 1]] + items[i - 1]);
    }
  }

  cout << dp[n][w] << "\n";

  return 0;
}