#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/replace-words/
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        map<string, string> hash;
        int n = dictionary.size();
        for (int i = 0; i < n; i++) {
            hash[dictionary[i]] = dictionary[i];
        }
        
        stringstream ss(sentence);
        string word, ans;
        while (ss >> word) {
            string a;
            for (int i = 0; i < word.size(); i++) {
                a.push_back(word[i]);
                if (hash.find(a) != hash.end()) {
                    word = hash[a];
                    break;
                }
            }
            
            ans.append(word + " ");
        }
        
        ans.pop_back();
        return ans;
    }
};