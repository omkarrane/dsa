#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int cp = x;
        int res = 0;
        while (cp != 0) {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && cp % 10 > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && cp % 10 < -8))
                return 0;
            res *= 10;
            res += cp % 10;
            cp /= 10;
        }
        
        return res;
    }
};