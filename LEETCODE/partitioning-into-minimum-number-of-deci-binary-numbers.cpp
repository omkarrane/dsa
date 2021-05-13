#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
/**
  * We can greedily make every character '0' first.
  * That would require us to iterate through the whole string.
  * For every character, we observe that we need to delete s[i] from it to make it 0.
  * Hence, the answer is to find the max element from the string.
 */
class Solution {
public:
    int minPartitions(string s) {
        int mx = 0;
        for (int i = 0; i < s.size(); i++)
            mx = max(mx, s[i] - '0');
        
        return mx;
    }
};