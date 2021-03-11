#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target)
                return mid;
            
            if (arr[mid] >= arr[low]) {
                if (target >= arr[low] && target < arr[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else {
                if (target <= arr[high] && target > arr[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        
        return -1;
    }
};