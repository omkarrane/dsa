#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end())
                m[nums[i]] = 0;
            m[nums[i]]++;
        }
        
        int n = (nums.size() / 2) + 1;
        for (auto i : m) {
            if (i.second >= n)
                return i.first;
        }
        
        return -1;
    }
};