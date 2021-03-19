#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/length-of-last-word/
/**
 * first get to a point where there are no trailing spaces
 * then count the chars in the last word
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i > -1 && s[i] == ' ')
            i--;
        
        if (i < 0)
            return 0;
        
        int j = i;
        while (i > -1 && s[i] != ' ')
            i--;
        
        return max(j - i, 1);
    }
};