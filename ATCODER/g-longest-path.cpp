#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &dp, map<int, vector<int>> &g, int v)
{
  if (dp[v] != -1)
    return dp[v];

  vector<int> adj = g[v];
  int current = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    current = max(current, dfs(dp, g, adj[i]) + 1);
  }

  return dp[v] = current;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  map<int, vector<int>> g;
  int temp1, temp2;

  for (int i = 1; i <= m; i++)
  {
    cin >> temp1 >> temp2;
    g[temp1].push_back(temp2);
  }

  vector<int> dp(n + 1, -1);
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dfs(dp, g, i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";

  return 0;
}