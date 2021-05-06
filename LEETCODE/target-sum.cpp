#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/target-sum/
/**
 * this can be solved using recursion with memoization as every element can contribute to the current sum in 2 ways
 * either by adding to the current sum or by subtracting
 */
class Solution {
public:
    vector<vector<int>> dp;
    int mx = 1000;
    
    int combineSolver(vector<int> &nums, int k, int currSum, int index) {
        if (k == currSum && index == nums.size())
            return 1;
        if (index == nums.size())
            return 0;
        
        if (dp[mx + currSum][index] != -1)
            return dp[mx + currSum][index];
        
        int current = 0;
        current += combineSolver(nums, k, currSum - nums[index], index + 1);
        current += combineSolver(nums, k, currSum + nums[index], index + 1);
        
        return dp[mx + currSum][index] = current;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        dp = vector<vector<int>>(mx * 2, vector<int>(nums.size(), -1));
        return combineSolver(nums, target, 0, 0);
    }
};