#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/different-bits-sum-pairwise/
/**
 * here, we first consider that the array is only consisting of 0s and 1s
 * hence, the solution becomes set bits * unset bits
 * now, if we consider the original problem, we just check each and every bit of the integer (0..31)
 */
int Solution::cntBits(vector<int> &A) {
    long long ans = 0;
    long long mod = 1000000007;
    for (int i = 0; i < 32; i++) {
        long long ones = 0, zeroes = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] & (1 << i))
                ones++;
            else
                zeroes++;
        }
        
        long long current = ones * zeroes * 2ll;
        ans += current;
        ans %= mod;
    }
    
    return ans % mod;
}
