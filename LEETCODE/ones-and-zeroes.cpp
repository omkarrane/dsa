#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ones-and-zeroes/
/**
 * to solve this question, first we try to write a brute force approach using backtracking
 * now as we can see, this approach will definitely give a TLE, we think of using memoization as after dry running we find overlapping sub-problems
 * so we need to memoize using a 3d DP because our state depends on currM, currN and currIndex
 */
class Solution {
public:
    vector<vector<vector<int>>> dp;
    
    int combineHelper(vector<string>& strs, int m, int n, int currM, int currN, int index) {
        if (index == strs.size())
            return 0;
        
        if (dp[currM][currN][index] != -1)
            return dp[currM][currN][index];
        
        int a = 0, b = 0;
        for (int i = 0; i < strs[index].size(); i++) {
            if (strs[index][i] == '1')
                b++;
            else
                a++;
        }
        
        int with = 0, without = 0;
        if (currM + a <= m && currN + b <= n) {
            with = 1 + combineHelper(strs, m, n, currM + a, currN + b, index + 1);
        }
        
        without = combineHelper(strs, m, n, currM, currN, index + 1);
        
        return dp[currM][currN][index] = max(with, without);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp = vector<vector<vector<int>>>(m + 1);
        for (int i = 0; i <= m; i++) {
            dp[i] = vector<vector<int>>(n + 1);
            for (int j = 0; j <= n; j++) {
                dp[i][j] = vector<int>(strs.size(), -1);
            }
        }
        return combineHelper(strs, m, n, 0, 0, 0);
    }
};