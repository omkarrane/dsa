#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        bool flag = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    flag = false;
                    break;
                }
            }
            
            if (!flag)
                break;
        }
        
        return res;
    }
};