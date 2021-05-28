#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/can-place-flowers/
/**
 * we can just simulate the process and see if n == 0
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0)
            return true;
        
        if (flowerbed.size() == 1)
            return (flowerbed[0] == 0 && n == 1);
        
        for (int i = 0; i < flowerbed.size(); i++) {
            if (i == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            else if (i == flowerbed.size() - 1 && flowerbed[i] == 0 && flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            else if (i > 0 && flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
            
            
            if (n == 0)
                return true;
        }
        
        return n == 0;
    }
};