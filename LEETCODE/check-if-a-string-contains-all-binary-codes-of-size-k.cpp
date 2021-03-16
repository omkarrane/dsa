#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solution/
/**
 * for every string of length k from 's', mark the current number as true
 * the number can be converted from binary but rolling hash function can be handy here as exactly at most bits are changing at a time
 * hence a left shift and adding current number can be done to calculate decimal format for the binary string 
*/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int p = 1 << k;
        int allOne = p - 1;
        vector<bool> check(p, false);
        int hashCode = 0;
        
        for (int i = 0; i < s.size(); i++) {
            hashCode = (hashCode << 1) & allOne;
            hashCode |= s[i] - '0';
            if (i >= k - 1)
                check[hashCode] = true;
        }
        
        for (int i = 0; i < p; i++)
            if (!check[i])
                return false;
        
        return true;
    }
};