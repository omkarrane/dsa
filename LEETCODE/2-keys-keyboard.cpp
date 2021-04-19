#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/2-keys-keyboard/
/**
 * we can use dp to solve this problem where we fill the table in a bottom up manner
 */
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = 0;
        for (int k = 1; k <= n; k++) {
            int val = dp[k] + 2;
            for (int i = k * 2; i <= n; i+=k) {
                dp[i] = min(dp[i], val);
                val++;
            }
        }
        
        return dp[n];
    }
};