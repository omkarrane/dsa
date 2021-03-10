#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/arithmetic-subarrays/
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        
        vector<bool> ans;
        for (int i = 0; i < n; i++) {
            int low = l[i];
            int high = r[i];
            if (high - low == 0) {
                ans.push_back(true);
                continue;
            }
            vector<int> nums1;
            for (int j = low; j <= high; j++)
                nums1.push_back(nums[j]);
            
            sort(nums1.begin(), nums1.end());
            bool flag = true;
            int diff = nums1[1] - nums1[0];
            for (int j = 1; j < nums1.size(); j++) {
                if (diff != (nums1[j] - nums1[j - 1])) {
                    flag = false;
                    break;
                }
            }
            
            ans.push_back(flag);
        }
        
        return ans;
    }
};