#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
/**
 * use a open counter to count number of opening brackets
 * for every closing bracket, decrement open counter
 * also check for invalid paranthesis by checking if open counter is 0 before decrementing
 */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int open = 0, ans = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(') {
                open++;
            }
            else {
                if (open == 0)
                    ans++;
                else
                    open--;
            }
        }
        
        return ans + open;
    }
};