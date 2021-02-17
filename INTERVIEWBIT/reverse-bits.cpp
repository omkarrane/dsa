#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/reverse-bits/
unsigned int reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    unsigned int B = 0;
    int i = 0;
    while (A > 0) {
        if (A & 1) {
            B |= (1 << 31 - i);
        }
        A >>= 1;
        i++;
    }
    
    return B;
}
