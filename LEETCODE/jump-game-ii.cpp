#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/jump-game-ii/
/**
 * This can be thought of as a dynamic programming problem, where we use the results of the smaller problem to find the answer to a larger one
 * The dp relation is as follows dp[i] = min(dp[i], dp[j] + 1); where j ranges from i to i + nums[i]
 * The result state will be dp[0]; as the smallest sub-problem is the last index of the array where we have to reach.
 */
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e6);
        dp[n - 1] = 0;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j <= min(n - 1, i + nums[i]); j++) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        
        return dp[0];
    }
};