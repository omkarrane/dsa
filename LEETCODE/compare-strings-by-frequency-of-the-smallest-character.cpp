#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
class Solution {
public:
    int getFrequency(string a) {
        int arr[125] = {0};
        for (int i = 0; i < a.size(); i++)
            arr[a[i]]++;
        
        for (int i = 0; i < 125; i++)
            if (arr[i] > 0)
                return arr[i];
        
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> A;
        for (int i = 0; i < words.size(); i++) {
            int temp = getFrequency(words[i]);
            A.push_back(temp);
        }
        sort(A.begin(), A.end());
        
        vector<int> B;
        for (int i = 0; i < queries.size(); i++) {
            int f = getFrequency(queries[i]);
            int temp = upper_bound(A.begin(), A.end(), f) - A.begin();
            B.push_back(A.size() - temp);
        }
        
        return B;
    }
};