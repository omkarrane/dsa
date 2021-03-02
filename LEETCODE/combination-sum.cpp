#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    long long getSum(vector<int> &prefix) {
        long long sum = 0;
        for (int i = 0; i < prefix.size(); i++)
            sum += prefix[i];
        
        return sum;
    }
    
    void combineHelper(vector<vector<int>> &res, vector<int> &prefix, int B, int index, vector<int> &candidates) {
        long long pSum = getSum(prefix);
        if (pSum == B) {
            res.push_back(prefix);
            return;
        }
        
        if (pSum > B)
            return;
        
        for (int i = index; i < candidates.size(); i++) {
            prefix.push_back(candidates[i]);
            combineHelper(res, prefix, B, i, candidates);
            prefix.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> prefix;
        combineHelper(res, prefix, target, 0, candidates);
        return res;
    }
};