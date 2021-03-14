#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> hash;
        int n = strs.size();
        
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for (auto i : hash) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};