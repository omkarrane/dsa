#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/the-kth-factor-of-n/
/**
 * check for all i's from 1 to n inclusive if it divides n
*/
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                k--;
            
            if (k == 0)
                return i;
        }
        
        return -1;
    }
};