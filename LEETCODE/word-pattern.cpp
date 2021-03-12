#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-pattern/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> hash1;
        map<char, string> hash2;
        
        int n = 0;
        stringstream ss(s);
        string word;
        while (ss >> word)
            n++;
        if (n != pattern.size())
            return false;
        
        stringstream ss1(s);
        int i = 0;
        while (ss1 >> word) {
            if (hash1.find(word) == hash1.end()) {
                if (hash2.find(pattern[i]) != hash2.end())
                    return false;
                
                hash2[pattern[i]] = word;
                hash1[word] = pattern[i];
            }
            else if (pattern[i] != hash1[word])
                return false;
            i++;
        }
        
        return true;
    }
};