#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
/**
 * because the strings are of equal length, any character which is present in t but not in s will be replaced by a character in s which is not in t
 * just maintain 2 arrays of 26 length
 * increment for every character in s and t
 * count the mismatch
*/
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arrS(26, 0);
        vector<int> arrT(26, 0);
        for (int i = 0; i < s.size(); i++) {
            arrS[s[i] - 'a']++;
            arrT[t[i] - 'a']++;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (arrS[i] < arrT[i])
                ans += arrT[i] - arrS[i];
        }
        
        return ans;
    }
};