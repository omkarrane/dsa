#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/gray-code/
/**
 * a simple observation is that the next 2^i iterations would be 2^i + ans[j] for every j from size to 1
 * hence we could just use 2 for loops for solving this
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        
        for (int i = 1; i < n; i++) {
            for (int j = ans.size()- 1; j >= 0; j--) {
                ans.push_back(ans[j] | (1 << i));
            }
        }
        
        return ans;
    }
};