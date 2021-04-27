#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/
/**
 * this can be done in a way similar to longest palindrome subsequence, with a simple difference
 * the difference is that we need to fill the matrix diagonally
 * the choices depend on the following: when Si == Sj
 * dp[i][j] = dp[i + 1][j - 1] for (j - i + 1) > 2
 * dp[i][j] = dp[i + 1][j] && dp[i][j - 1] for (j - i + 1) <= 2
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        string ans;
        ans.push_back(s[0]);
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = false;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                    
                    if (dp[i + 1][j] && dp[i][j - 1]) {
                        dp[i][j] = true;
                    }
                }
                
                if (dp[i][j] && ans.size() < (j - i + 1)) {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        
        return ans;
    }
};