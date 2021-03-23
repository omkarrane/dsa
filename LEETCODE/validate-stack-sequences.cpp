#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/validate-stack-sequences/
/**
 * maintain 2 pointers i and j
 * if element popped[j] has already been pushed then check if st1.top() == popped[j]
 * if not, then return false
 * if element popped[j] has not been pushed yet then keep pushing till we encounter popped[j]
 */
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st1;
        int n = pushed.size();
        unordered_map<int, int> hash;
        for (int k = 0; k < n; k++) {
            hash[pushed[k]] = k;
        }
        
        int i = 0, j = 0;
        while (j < n) {
            if (hash[popped[j]] >= i) {
                if (i < n && pushed[i] == popped[j]) {
                    i++;
                    j++;
                }
                else {
                    while (i < n && pushed[i] != popped[j])
                        st1.push(pushed[i++]);

                    if (i < n && pushed[i] != popped[j])
                        return false;
                    i++;
                    j++;    
                }
            }
            else {
                if (st1.empty() || st1.top() != popped[j])
                    return false;
                st1.pop();
                j++;
            }
        }
        
        return true;
    }
};