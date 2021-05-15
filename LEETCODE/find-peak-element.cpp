#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-peak-element/
/**
  * Think of this as finding a peak on a mountain.
  * We do this using binary search.
  * First we check if the mid, we achieved is the peak or not.
    * This is done with 3 checks
    * First check if mid is the first element. In this case, only check right.
    * Second is when mid is the last element. In this case, only check left.
    * Third is check both sides.
  * If yes, then we return this index.
  * If not, we see which side amongst the left or right is larger. If left is larger, then it has a greater likelihood of finding the peak element. Else we go right.
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        
        int low = 0;
        int high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1])
                    return mid;
                low = mid + 1;
            }
            else if (mid == n - 1) {
                if (nums[mid] > nums[mid - 1])
                    return mid;
                high = mid - 1;
            }
            else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if (nums[mid] < nums[mid + 1])
                low = mid + 1;
            else
                high = mid - 1;   
        }
        
        return -1;
    }
};