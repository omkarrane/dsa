#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/increasing-triplet-subsequence/
/**
  * The basic idea behind this approach is we keep track of the first 2 smaller elements using 2 variables.
  * We update first if current is smaller, if not, then we check it with second, if not means the current element is larger than both 2. Also we maintain the invariant that first < second. Hence, we return true.
  * Else we return false.
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        
        for (int i : nums) {
            if (i <= first)
                first = i;
            else if (i <= second)
                second = i;
            else
                return true;
        }
        
        return false;
    }
};