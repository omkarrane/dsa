#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;
        sort(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++) {
            if (binary_search(nums1.begin(), nums1.end(), nums2[i]))
                ans.insert(nums2[i]);
        }
        
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};