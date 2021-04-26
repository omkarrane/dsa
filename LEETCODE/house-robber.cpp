#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/house-robber/
/**
 * dp state can be defined as dp[i] = max(dp[i - 1], dp[i - 2] + Ai)
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        
        for (int i = 2; i < n + 2; i++) {
            int a = dp[i - 1];
            a = max(a, dp[i - 2] + nums[i - 2]);
            dp[i] = a;
        }
        
        return dp[n + 1];
    }
};