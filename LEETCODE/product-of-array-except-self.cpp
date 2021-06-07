#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/
/**
 * we can solve this by using O(n) extra space for prefix and suffix array
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), suffix(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i - 1] * nums[i];
        
        for (int i = nums.size() - 2; i >= 0; i--)
            suffix[i] = suffix[i + 1] * nums[i];
        
        vector<int> ans(nums.size());
        ans[0] = suffix[1];
        ans[nums.size() - 1] = prefix[nums.size() - 2];
        
        for (int i = 1; i < nums.size() - 1; i++)
            ans[i] = prefix[i - 1] * suffix[i + 1];
        
        return ans;
    }
};