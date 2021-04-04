#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/combination-sum-iii/
/**
 * a simple backtracking would solve the problem as the size of input is low
 */
class Solution {
public:
    void combineHelper(vector<vector<int>> &res, vector<int> &prefix, int &k, int &n, int index, int currSum) {
        if (currSum == n) {
            if (prefix.size() == k)
                res.push_back(prefix);
            return;
        }
        
        if (currSum > n)
            return;
        
        for (int i = index; i <= 9; i++) {
            currSum += i;
            prefix.push_back(i);
            combineHelper(res, prefix, k, n, i + 1, currSum);
            currSum -= i;
            prefix.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> current;
        combineHelper(res, current, k, n, 1, 0);
        return res;
    }
};