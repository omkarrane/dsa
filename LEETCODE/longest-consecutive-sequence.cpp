#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/
/**
  * We can solve this question using hashing.
  * We first put all the elements in a set which will give us a constant time search.
  * Then we iterate through all the elements in the set and iterate through the set for every starting sequence.
  * We do this when we don't find `element - 1` in the set.
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int i : nums)
            hashSet.insert(i);
        
        int mx = 0;
        for (int i : hashSet) {
            if (hashSet.find(i - 1) == hashSet.end()) {
                int current = 1;
                int element = i + 1;
                
                while (hashSet.find(element) != hashSet.end()) {
                    element++;
                    current++;
                }
                
                mx = max(mx, current);
            }
        }
        
        return mx;
    }
};