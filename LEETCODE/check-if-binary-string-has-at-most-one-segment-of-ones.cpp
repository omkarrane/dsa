#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == '1' && s[i] == '0' && !flag)
                flag = true;
            else if (s[i - 1] == '0' && s[i] == '1' && flag)
                return false;
        }
        
        return true;
    }
};