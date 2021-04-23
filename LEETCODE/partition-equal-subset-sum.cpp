#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-equal-subset-sum/
/**
 * we can reduce this problem to finding target sum where sum is (sum of array) / 2
 * also as there is a optimal substructure and overlapping subproblems, we can apply dp
 */
// Recursive Solution
class Solution {
public:
    vector<vector<int>> dp;
    
    bool combineHelper(vector<int> &nums, int target, int index, int current) {
        if (current == target)
            return true;
        
        if (current > target)
            return false;
        
        if (index == nums.size())
            return false;
        
        if (dp[index][current] != -1)
            return dp[index][current] == 1;
        
        
        bool res = combineHelper(nums, target, index + 1, current + nums[index]) ||
                combineHelper(nums, target, index + 1, current);
        
        if (res)
            dp[index][current] = 1;
        else
            dp[index][current] = 0;
        
        return res;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        
        dp = vector<vector<int>>(nums.size() + 1, vector<int>(sum / 2 + 1, -1));
        return combineHelper(nums, sum / 2, 0, 0);
    }
};

// Iterative Solution
class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        
        if (sum % 2 == 1)
            return false;
        
        int target = sum / 2;
        vector<vector<bool>> dp = vector<vector<bool>>(nums.size() + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= nums.size(); i++)
            dp[i][0] = true;
        
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        
        return dp[nums.size()][target];
    }
};