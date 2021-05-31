#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-sorted-vowel-strings/
/**
  * We can recursively find every possible combination first.
  * Now as there are 2 changing parameters currLength and index, we use a 2D array to memoize it.
 */
class Solution {
public:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<vector<int>> dp;
    
    int combineSolver(int n, int currLength, int index) {
        if (n == currLength)
            return 1;
        
        if (dp[currLength][index] != -1)
            return dp[currLength][index];
        
        int curr = 0;
        for (int i = index; i < vowels.size(); i++)
            curr += combineSolver(n, currLength + 1, i);
        
        return dp[currLength][index] = curr;
    }
    
    int countVowelStrings(int n) {
        dp = vector<vector<int>>(n + 1, vector<int>(5, -1));
        return combineSolver(n, 0, 0);
    }
};