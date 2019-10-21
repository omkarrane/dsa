#include<bits/stdc++.h>

using namespace std;

int knapsack(int S, int size[], int val[], int N)
{
  int dp[N+1][S+1];

  for(int i = 0; i <= N; i++)
  {
    for(int s = 0; s <= S; s++)
    {
      if(i == 0 || s == 0)
        dp[i][s] = 0;
      else if(size[i - 1] <= s)
      {
        dp[i][s] = max(val[i - 1] + dp[i - 1][s - size[i - 1]], dp[i - 1][s]);
      }
      else
        dp[i][s] = dp[i - 1][s];
    }
  }

  return dp[N][S];
}

int main()
{
  int S, N;
  cin >> S >> N;

  int size[N], val[N];

  for(int i = 0; i < N; i++)
  {
    cin >> size[i] >> val[i];
  }

  int result = knapsack(S, size, val, N);
  cout << result << endl;

  return 0;
}