#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/water-bottles/
/**
 * we can just simulate the process and calculate the answer
 */
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        int leftOvers = 0;
        while (numBottles > 0) {
            ans += numBottles;
            int temp = (numBottles + leftOvers) / numExchange;
            leftOvers = (numBottles + leftOvers) % numExchange;
            numBottles = temp;
        }
        
        return ans;
    }
};