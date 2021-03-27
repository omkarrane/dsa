#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-subsets/
/**
 * as we need to check if every b[i] is a subset of a[j], we can generate a bmax word which contains max count of every letter from each word
 */
class Solution {
public:
    vector<int> count(string &a) {
        vector<int> arr(26);
        for (int i = 0; i < a.size(); i++)
            arr[a[i] - 'a']++;
        
        return arr;
    }
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> ans;
        vector<int> bmax(26);
        for (int i = 0; i < B.size(); i++) {
            vector<int> b = count(B[i]);
            for (int j = 0; j < 26; j++)
                bmax[j] = max(b[j], bmax[j]);
        }
        
        for (int i = 0; i < A.size(); i++) {
            bool flag = true;
            vector<int> a = count(A[i]);
            for (int j = 0; j < 26; j++) {
                if (a[j] < bmax[j]) {
                    flag = false;
                    break;
                }
            }
            
            if (flag)
                ans.push_back(A[i]);
        }
        
        return ans;
    }
};