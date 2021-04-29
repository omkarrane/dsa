#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-binary-search-trees/
/**
 * 
 */
class Solution {
public:
    vector<int> dp;
    
    int combineSolver(int n) {
        if (n == 0 || n == 1)
            return 1;
        
        if (dp[n] != -1)
            return dp[n];
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += combineSolver(n - i - 1) * combineSolver(i);
        }
        
        return dp[n] = ans;
    }
    
    int numTrees(int n) {
        int ans = 0;
        dp = vector<int>(n + 1, -1);
        
        return combineSolver(n);
    }
};