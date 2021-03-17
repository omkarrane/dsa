#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-string-chain/
/**
 * sort the words first according to length
 * for each word remove one character everytime and check if the modified word was encountered previously
 * if yes, then update[curr] = modified + 1
 * if no, then do nothing
 * collect max for every word to return
*/
class Solution {
public:
    static bool compare(string &a, string &b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), compare);

        int ans = 1;
        for (string w : words) {
            for (int i = 0; i < w.size(); i++) {
                string charRemoved = w.substr(0, i) + w.substr(i + 1);
                if (dp.find(charRemoved) != dp.end())
                    dp[w] = max(dp[w], dp[charRemoved] + 1);
                else
                    dp[w] = max(dp[w], 1);
            }

            ans = max(ans, dp[w]);
        }

        return ans;
    }
};