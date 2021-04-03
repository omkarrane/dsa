#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partition-labels/
/**
 * this can be solved using a greedy approach where in we choose the smallest partition
 * we first store the last occurrence of every character in the string
 * then we greedily find the smallest partition to divide
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> last;
        
        for (int i = 0; i < s.size(); i++)
            last[s[i]] = i;
        
        vector<int> ans;
        int lastPartition = -1, prev = -1;
        for (int i = 0; i < s.size(); i++) {
            lastPartition = max(lastPartition, last[s[i]]);
            if (lastPartition == i) {
                ans.push_back(i - prev);
                prev = i;
                lastPartition = i;
            }
        }
        
        return ans;
    }
};