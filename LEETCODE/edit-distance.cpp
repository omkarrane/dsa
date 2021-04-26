#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/edit-distance/
/**
 * dynamic programming recurrence relation
 * when si != sj:
 *  dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1[j-1] + 1)
 */
class Solution {
public:
    vector<vector<int>> dp;
        
    int combineSolver(string &word1, string &word2, int i, int j) {
        if (i == word1.size())
            return word2.size() - j;
        
        if (j == word2.size())
            return word1.size() - i;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (word1[i] == word2[j])
            return dp[i][j] = combineSolver(word1, word2, i + 1, j + 1);

        dp[i][j] = combineSolver(word1, word2, i + 1, j) + 1;  // del
        dp[i][j] = min(dp[i][j], combineSolver(word1, word2, i, j + 1) + 1);  // insert
        dp[i][j] = min(dp[i][j], combineSolver(word1, word2, i + 1, j + 1) + 1);  // replace
        return dp[i][j];
    }
    
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        dp = vector<vector<int>>(n1 + 1, vector<int>(n2 + 1, -1));
        return combineSolver(word1, word2, 0, 0);
    }
};