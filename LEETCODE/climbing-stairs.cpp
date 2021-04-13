#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/climbing-stairs/
/**
 * we can see that in order to reach ith stair, we need to atleast reach i-1th or i-2th stair
 * hence, total number of ways we can reach ith stair is given by the following recurrence formula
 * T(i) = T(i - 1) + T(i - 2)
 * this can be solved as finding the ith fibonacci number
 */
class Solution {
public:
    int climbStairs(int n) {
        int t1 = 0, t2 = 1, t3 = 0;
        
        for (int i = 1; i <= n; i++) {
            t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        
        return t3;
    }
};