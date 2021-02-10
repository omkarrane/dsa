#include <bits/stdc++.h>
using namespace std;

int solve(int A, int B) {
    int ans = 0;
    int cpy1 = A + 1, cpy2 = B + 1;
    while (cpy1 <= 8 && cpy2 <= 8) {
        ans++;
        cpy1++;
        cpy2++;
    }
    
    cpy1 = A - 1, cpy2 = B - 1;
    while (cpy1 >= 1 && cpy2 >= 1) {
        ans++;
        cpy1--;
        cpy2--;
    }
    
    cpy1 = A - 1, cpy2 = B + 1;
    while (cpy1 >= 1 && cpy2 <= 8) {
        ans++;
        cpy1--;
        cpy2++;
    }
    
    cpy1 = A + 1, cpy2 = B - 1;
    while (cpy1 <= 8 && cpy1 >= 1) {
        ans++;
        cpy1++;
        cpy2--;
    }
    
    return ans;
}
