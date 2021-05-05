#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximal-square/
/**
 * dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 for all matrix[i-1][j-1] == '1'
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 || j == 1) {
                    if (matrix[i - 1][j - 1] == '1')
                        dp[i][j] = 1;
                }      
                else {
                    if (matrix[i - 1][j - 1] == '1') {
                        int temp = min(dp[i - 1][j], dp[i][j - 1]);
                        temp = min(temp, dp[i - 1][j - 1]);
                        dp[i][j] = temp + 1;      
                    }
                }
                    
                
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans * ans;
    }
};