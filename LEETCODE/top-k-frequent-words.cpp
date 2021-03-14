#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-words/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> hash1;
        map<int, set<string>, greater<int>> hash2;
        int n = words.size();
        
        for (int i = 0; i < n; i++) {
            if (hash1.find(words[i]) == hash1.end())
                hash1[words[i]] = 0;
            hash1[words[i]]++;
        }
        
        for (auto i : hash1) {
            hash2[i.second].insert(i.first);
        }
        
        vector<string> ans;
        for (auto i : hash2) {
            for (string s : i.second) {
                if (ans.size() == k)
                    return ans;
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};