#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-primes/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        
        int ans = n - 2;
        bool sieve[n];
        fill(sieve, sieve + n, true);
        
        for (int i = 2; i * i < n; i++) {
            if (!sieve[i])
                continue;
            for (int j = i * i; j < n; j += i) {
                if (!sieve[j])
                    continue;
                sieve[j] = false;
                ans--;
            }
        }
        
        
        return ans;
    }
};