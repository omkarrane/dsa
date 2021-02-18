#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/implement-power-function/
int pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (n == 0)
        return 1 % d;
    
    if (x < 0)
        x = d - abs(x);
        
    if (n == 1)
        return x % d;
        
    long long x1 = x;
    long long result = 1;
    while (n > 0) {
        if (n & 1) {
            result *= x1;
            result %= d;
        }
    
        x1 *= x1;
        x1 %= d;
        n >>= 1;
    }
    
    return result;
}
