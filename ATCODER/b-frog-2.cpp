#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> dp(n + 1, 0);

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + abs(arr[i - 1] - arr[i - 2]);
    for (int j = 2; j <= k; j++)
    {
      if (i > j)
      {
        dp[i] = min(dp[i], dp[i - j] + abs(arr[i - 1] - arr[i - j - 1]));
      }
    }
  }

  cout << dp[n] << "\n";

  return 0;
}