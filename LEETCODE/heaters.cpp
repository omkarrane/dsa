#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/heaters/
class Solution {
public:
    bool isPossible(vector<int> &houses, vector<int> &heaters, long long radius) {
        int i = 0, j = 0;
        while (j < heaters.size()) {
            int left = heaters[j] - radius;
            int right = heaters[j] + radius;
            while (i < houses.size() && left <= houses[i] && houses[i] <= right)
                i++;
            j++;
        }
        
        return i == houses.size();
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int low = 0;
        int high = 1000000000;
        int ans = 1000000000;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool possible = isPossible(houses, heaters, mid);
            
            if (possible) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};