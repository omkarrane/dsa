#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-operations-to-make-array-equal/
class Solution {
public:
    int minOperations(int n) {
        if (n == 0 || n == 1)
            return 0;
        
        int ans = 0;
        int i = 1;
        int add = 1;
        while (i < n) {
            ans += add;
            i++;
            if (i % 2 == 1)
                add++;
        }
        
        return ans;
    }
};