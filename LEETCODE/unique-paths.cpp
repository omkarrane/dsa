#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-paths/
/**
 * as optimal sub-structure and overlapping sub-problems can be found here, we can solve this using dp
 */
class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m][n];
    }
};