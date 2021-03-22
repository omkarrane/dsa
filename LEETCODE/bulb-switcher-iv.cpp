#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/bulb-switcher-iv/
/**
 * a flip operation will flip all bulbs to the right of it
 * so the minimum number of switch operations we would require is the count of subsequences of either '0' or '1'
*/
class Solution {
public:    
    int minFlips(string target) {
        int ans = 0;
        int n = target.size();
        int i = 0;
        while (i < n && target[i] != '1')
            i++;
        
        if (i == n)
            return 0;
        
        while (i < n) {
            while (i < n && target[i] == target[i + 1])
                i++;
            ans++;
            i++;
        }
        
        return ans;
    }
};