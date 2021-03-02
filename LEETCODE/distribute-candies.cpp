#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/distribute-candies/
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> s(candyType.begin(), candyType.end());
        int n = candyType.size() / 2;
        if (s.size() > n)
            return n;
        return s.size();
    }
};