#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/**
 * This can be simply solved using recursion and backtracking
 */
class Solution {
public:
    unordered_map<char, string> m{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void combineSolver(vector<string> &res, string &curr, string &digits, int index) {
        if (index == digits.size()) {
            if (curr.empty())
                return;
            res.push_back(curr);
            return;
        }
        
        for (int i = 0; i < m[digits[index]].size(); i++) {
            curr.push_back(m[digits[index]][i]);
            combineSolver(res, curr, digits, index + 1);
            curr.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return vector<string>();
        
        vector<string> res;
        string current;
        combineSolver(res, current, digits, 0);
        
        
        return res;
    }
};