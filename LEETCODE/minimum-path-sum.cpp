#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-path-sum/
/**
 * through a dry run we can clearly observe that this is a dp problem
 * the dp relation can be given as follows
 * dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + gridVal[i][j]
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() + 1;
        int m = grid[0].size() + 1;
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++)
            dp[i] = vector<int>(m, 0);
        
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (i == 1 && j == 1)
                    dp[i][j] = grid[i - 1][j - 1];
                else if (i == 1)
                    dp[i][j] = dp[i][j - 1] + grid[i - 1][j - 1];
                else if (j == 1)
                    dp[i][j] = dp[i - 1][j] + grid[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        
        return dp[n - 1][m - 1];
    }
};