#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/trailing-zeroes/
int solve(int A) {
    int count = 0;
    while (A > 0) {
        if ((A & 1) == 1)
            break;
        count++;
        A >>= 1;
    }
    
    return count;
}
