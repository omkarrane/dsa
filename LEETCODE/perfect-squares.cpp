#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/perfect-squares/
/**
 * we can use dp to solve this problem
 * dp(n) = min(dp(n - i*i)) + 1
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
            for (int k = 1; k*k <= i; k++) {
                dp[i] = min(dp[i], dp[i - k*k] + 1);
            }
        }
        
        return dp[n];
    }
};