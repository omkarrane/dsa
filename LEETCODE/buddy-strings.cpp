#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/buddy-strings/
/**
 * if strings are equal, find a char which is repeated 2 or more times
 * if strings are not equal, check iteratively for exactly 2 mismatches
 * check if swapping them makes them equal
*/
class Solution {
public:
    bool buddyStrings(string a, string b) {
        if (a.size() != b.size())
            return false;
        
        int n = a.size();
        
        if (a == b) {
            vector<int> arr(26, 0);
            for (int i = 0; i < n; i++) {
                arr[a[i] - 'a']++;
                if (arr[a[i] - 'a'] == 2)
                    return true;
            }
            
            return false;
        }
        
        int count = 0, first = -1, second = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i])
                continue;
            
            if (count == 2)
                return false;
            
            if (first == -1)
                first = i;
            else
                second = i;
            
            count++;
            
        }
        
        if (count != 2)
            return false;
        
        return a[first] == b[second] && a[second] == b[first];
    }
};