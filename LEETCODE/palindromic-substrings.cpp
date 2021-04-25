#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindromic-substrings/
/**
 * this can be done in a way similar to longest palindrome subsequence, with a simple difference
 * the difference is that we need to fill the matrix diagonally
 * the choices depend on the following: when Si == Sj
 * dp[i][j] = dp[i + 1][j - 1] for (j - i + 1) > 2
 * dp[i][j] = dp[i + 1][j] && dp[i][j - 1] for (j - i + 1) <= 2
 * once we have the dp matrix, we count the number of true values for all substrings
 */
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        int ans = n;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = len + i - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    
                    if (dp[i + 1][j] && dp[i][j - 1])
                        dp[i][j] = true;
                    
                    if (dp[i][j])
                        ans++;
                }
            }
        }
        
        return ans;
    }
};