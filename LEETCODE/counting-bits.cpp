#include <bits/stdc++.h>
using namespace std;

// http://leetcode.com/problems/counting-bits/
/**
 * can be solved using brian kernighans algorithm for finding the number of set bits
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            int curr = i;
            int count = 0;
            while (curr != 0) {
                curr &= (curr - 1);
                count++;
            }
            ans[i] = count;
        }
        
        return ans;
    }
};