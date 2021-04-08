#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/max-consecutive-ones-iii/
/**
 * we can use 2 pointers approach for this
 * we maintain a j variable which points to start of the current window
 * once we exhaust k by using it, for every arr[i] == 0, we shrink the window till we recover one k
 */
class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int ans = 0, j = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0 && k > 0)
                k--;
            else if (arr[i] == 0 && k == 0) {
                while (j < i && arr[j] != 0)
                    j++;
                
                j++;
            }
            
            ans = max(ans, i - j + 1);
        }
        
        return ans;
    }
};