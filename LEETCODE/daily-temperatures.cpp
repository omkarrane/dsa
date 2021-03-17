#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/daily-temperatures/
/**
 * can be solved using stack as we need to find the nearest largest temperature to the right 
*/ 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> S;
        int n = T.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!S.empty()) {
                if (T[S.top()] > T[i]) {
                    ans[i] = S.top() - i;
                    break;
                }
                S.pop();
            }
            
            S.push(i);
        }
        
        return ans;
    }
};