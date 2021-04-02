#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/
/**
 * we can do this via backtracking by using a vector<bool> for used indexes
 */
class Solution {
public:
    void combineHelper(vector<vector<int>> &ans, vector<int> &prefix, vector<int> &nums, vector<bool> &used) {
        if (prefix.size() == nums.size()) {
            ans.push_back(prefix);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            prefix.push_back(nums[i]);
            combineHelper(ans, prefix, nums, used);
            used[i] = false;
            prefix.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> prefix;
        vector<bool> used(nums.size(), false);
        combineHelper(ans, prefix, nums, used);
        return ans;
    }
};