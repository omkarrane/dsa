#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
/**
 * just maintain 2 maps to count the number of unique characters
 * can do a sliding window to count the occurences and check the size of 2 maps
*/
class Solution {
public:
    int numSplits(string s) {
        unordered_map<char, int> arr1, arr2;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            arr2[s[i]]++;
        }
        
        for (int i = 0; i < s.size() - 1; i++) {
            arr1[s[i]]++;
            arr2[s[i]]--;
            if (arr2[s[i]] == 0)
                arr2.erase(s[i]);
            
            if (arr1.size() == arr2.size())
                ans++;
        }
        
        return ans;
    }
};