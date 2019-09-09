#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n], dp[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    long long cnt = 1;
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
      if (arr[i - 1] <= arr[i])
        dp[i] = dp[i - 1] + 1;
      else
        dp[i] = 1;
      cnt += dp[i];
    }

    cout << cnt << endl;
  }
  return 0;
}