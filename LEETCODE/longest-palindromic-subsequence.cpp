#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-subsequence/
/**
 * the recurrence relation here would be
 * when s[i] == s[j]: T(i, j) = T(i + 1, j - 1) + 2
 * when s[i] != s[j]: T(i, j) = max(T(i + 1, j), T(i, j - 1))
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;  // this is done to initialize the diagonals
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};