#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
class Solution {
public:
    bool stringMatching(string &a, string &b) {
        int j = 0;
        int count = 0;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == a[j]) {
                j++;
                count++;
                continue;
            }
            else {
                bool flag = false;
                while (j < a.size()) {
                    if (a[j] == b[i]) {
                        flag = true;
                        count++;
                        j++;
                        break;
                    }
                    j++;
                }
                
                if (!flag)
                    return false;
            }
        }
        
        return count == b.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
        string ans = "";
        
        for (int i = 0; i < d.size(); i++) {
            if (stringMatching(s, d[i]) && d[i].size() > ans.size()) {
                ans = d[i];
            }
        }
        
        return ans;
    }
};