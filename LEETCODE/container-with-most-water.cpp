#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/
/**
* As we can see, the water filled is limited by the height of the shorter line.
* Also, the farther the lines are, the more water it can contain.
* Hence, we can use a 2-pointer approach to solve this question.
* Keep 1 pointer at the start and the other at the end.
* Change the pointer pointing to the smaller line amongst the 2.
* Keep updating max answer for every iteration. 
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        
        int mx = 0;
        while (i < j) {
            int curr = min(height[i], height[j]) * (j - i);
            mx = max(mx, curr);
            
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        
        return mx;
    }
};