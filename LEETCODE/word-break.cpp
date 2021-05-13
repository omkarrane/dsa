#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-break/
/**
  * Once we first try to solve this recursively, we observe that this has overlapping subproblems.
  * First approach is we pass the substring in the recursively with the base assumption that empty string can always be made with the wordSet.
  * Second approach is we start iterating from the 0th index and keep finding a suitable match for the substring from 0 to i. If found, we recurse again but the start index will be i.
  * Third approach is basically a bottom up DP for the second approach.
 */
class Solution {
public:
    unordered_map<string, bool> dp;
    
    bool match(string &a, string &b) {
        for (int i = 0; i < b.size(); i++)
            if (a[i] != b[i])
                return false;
        
        return true;
    }
    
    bool combineSolver(string &s, vector<string> &dict) {
        if (s == "")
            return true;
        
        if (dp.find(s) != dp.end())
            return dp[s];
        
        bool current = false;
        for (int i = 0; i < dict.size(); i++) {
            bool lenMatch = match(s, dict[i]);
            if (lenMatch) {
                string a = s.substr(dict[i].size());
                current = current || combineSolver(a, dict);
            }
        }
        
        return dp[s] = current;
    } 
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return combineSolver(s, wordDict);
    }
};