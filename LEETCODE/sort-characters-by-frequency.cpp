#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash1;
        map<int, vector<char>, greater<int>> hash2;
        for (char c : s) {
            if (hash1.find(c) == hash1.end())
                hash1[c] = 0;
            hash1[c]++;
        }
        
        for (auto c : hash1) {
            hash2[c.second].push_back(c.first);
        }
        
        string ans;
        for (auto c : hash2) {
            for (auto v : c.second) {
                int i = c.first;
                while (i > 0) {
                    ans.push_back(v);
                    i--;
                }
            }
        }
        
        return ans;
    }
};