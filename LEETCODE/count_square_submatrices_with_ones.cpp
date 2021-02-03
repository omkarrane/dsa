#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-square-submatrices-with-all-ones/
class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp;

    for (int i = 0; i <= m; i++)
    {
      vector<int> temp;
      for (int j = 0; j <= n; j++)
      {
        if (i == 0 || j == 0)
          temp.push_back(0);
        else
          temp.push_back(matrix[i - 1][j - 1]);
      }
      dp.push_back(temp);
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (dp[i][j] == 1)
        {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
          ans += dp[i][j];
        }
      }
    }

    return ans;
  }
};