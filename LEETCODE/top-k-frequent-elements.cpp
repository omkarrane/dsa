#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m1;
        for (int i = 0; i < nums.size(); i++) {
            if (m1.find(nums[i]) == m1.end())
                m1[nums[i]] = 0;
            m1[nums[i]]++;
        }
        
        map<int, vector<int>, greater<int>> m2;
        for (auto i : m1) {
            m2[i.second].push_back(i.first);
        }
        
        vector<int> ans;
        for (auto i : m2) {
            for (int j = 0; j < i.second.size(); j++) {
                if (ans.size() == k)
                    return ans;
                ans.push_back(i.second[j]);
            }
        }
        
        return ans;
    }
};