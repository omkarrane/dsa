#include <bits/stdc++.h>
using namespace std;

int count(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &dp)
{
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
    return 0ll;

  if (grid[i][j] == '#')
    return 0ll;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (i == grid.size() - 1 && j == grid[0].size() - 1)
    return 1ll;

  long long current = 0ll;
  long long mod = 1e9 + 7;
  current += count(grid, i + 1, j, dp);
  current %= mod;
  current += count(grid, i, j + 1, dp);
  current %= mod;

  return dp[i][j] = current;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int h, w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));
  vector<vector<int>> dp(h, vector<int>(w, -1));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cin >> grid[i][j];
    }
  }

  long long ans = count(grid, 0, 0, dp);

  cout << ans << "\n";

  return 0;
}