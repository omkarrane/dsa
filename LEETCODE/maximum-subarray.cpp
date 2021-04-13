#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-subarray/
/**
 * we can use kadanes algorithm to solve this question
 * at every point, we need to make a decision on whether to include the current negative number or not for max sum
 * hence, a smart to include it or discard it is to take max of nums[i] or curr + nums[i]
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN, curr = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            mx = max(mx, curr);
        }
        
        return mx;
    }
};