#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/corporate-flight-bookings/
/**
  * We can use a sweep line algorithm to solve this question.
  * Here we add k seats to `start(i) - 1` booking and remove k seats from `last(i)`.
  * Once done, we just do a prefix sum to calculate the answer.
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        
        for (int i = 0; i < bookings.size(); i++) {
            res[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < n)
                res[bookings[i][1]] -= bookings[i][2];
        }
        
        for (int i = 1; i < n; i++)
            res[i] += res[i - 1];
        
        return res;
    }
};