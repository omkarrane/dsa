#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/reverse-integer/
int reverse(int A) {
    bool neg = false;
    if (A < 0) {
        A = abs(A);
        neg = true;
    }
    
    long long B = 0;
    while (A != 0) {
        if (B >= (INT_MAX / 10) && (A % 10) > 2)
            return 0;
        B *= 10;
        B += (A % 10);
        A /= 10;
    }
    
    if (neg)
        B *= -1;
        
    if (B >= INT_MAX || B <= INT_MIN)
        return 0;
    return B;
}
