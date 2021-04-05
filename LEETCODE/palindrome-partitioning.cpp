#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/
/**
 * we can use backtracking to solve this problem. we can also use some utility functions to assist us while backtracking
 */
class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    bool isValid(vector<string> &prefix, string &s) {
        int cnt = 0;
        for (int i = 0; i < prefix.size(); i++)
            cnt += prefix[i].size();
        
        return s.size() == cnt;
    }
    
    void combineHelper(vector<string> &prefix, string &currString, string &s, int index) {
        if (isValid(prefix, s)) {
            res.push_back(prefix);
            return;
        }
        
        for (int i = index; i < s.size(); i++) {
            currString.push_back(s[i]);
            if (isPalindrome(currString)) {
                prefix.push_back(currString);
                string a = "";
                combineHelper(prefix, a, s, i + 1);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        res = vector<vector<string>>();
        vector<string> prefix;
        string currString;
        combineHelper(prefix, currString, s, 0);
        return res;
    }
};