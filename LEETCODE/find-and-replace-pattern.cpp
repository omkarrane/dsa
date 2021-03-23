#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-and-replace-pattern/
/**
 * maintain 2 maps for every mapping from a to b and b to a
*/
class Solution {
public:
    bool isEqual(string &a, string &b) {
        if (a.size() != b.size())
            return false;
        
        unordered_map<char, char> hash1, hash2;
        for (int i = 0; i < a.size(); i++) {
            if (hash1.find(a[i]) == hash1.end() && hash2.find(b[i]) == hash2.end()) {
                hash1[a[i]] = b[i];
                hash2[b[i]] = a[i];
            }
            else if (hash1.find(a[i]) != hash1.end() && hash2.find(b[i]) != hash2.end()) {
                if (hash1[a[i]] == b[i] && hash2[b[i]] == a[i])
                    continue;
                else
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (isEqual(pattern, words[i]))
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};