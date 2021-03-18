#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reformat-the-string/
/**
 * split the split into nums and chars
 * compare their size differences if a valid string can be made
 * one by one put in the characters from nums and chars sequentially, maintaining the valid string 
*/ 
class Solution {
public:
    string reformat(string s) {
        string nums, chars;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] <= '9' && s[i] >= '0')
                nums.push_back(s[i]);
            else
                chars.push_back(s[i]);
        }
        
        int p = chars.size();
        int q = nums.size();
        if (abs(p - q) > 1)
            return "";
        
        string ans;
        int i1 = 0, j1 = 0;
        if (p < q) {
            ans.push_back(nums[j1++]);
            while (i1 < p && j1 < q) {
                ans.push_back(chars[i1++]);
                ans.push_back(nums[j1++]);
            }
        }
        else if (p == q) {
            while (i1 < p && j1 < q) {
                ans.push_back(chars[i1++]);
                ans.push_back(nums[j1++]);
            }
        }
        else {
            ans.push_back(chars[i1++]);   
            while (i1 < p && j1 < q) {
                ans.push_back(nums[j1++]);
                ans.push_back(chars[i1++]);
            }
        }
        
        return ans;
    }
};