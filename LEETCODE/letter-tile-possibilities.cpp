#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/letter-tile-possibilities/
/**
 * we can use a set to store all the unique possibilities
 * now use backtracking to generate all permutations of all subsets
 */
class Solution {
public:
    void combineHelper(set<string> &s, string &tiles, string &prefix, vector<bool> &used) {
        if (prefix.size() > 0)
            s.insert(prefix);
        
        for (int i = 0; i < tiles.size(); i++) {
            if (used[i])
                continue;
            prefix.push_back(tiles[i]);
            used[i] = true;
            combineHelper(s, tiles, prefix, used);
            used[i] = false;
            prefix.pop_back();
        }
    }
    
    int numTilePossibilities(string tiles) {
        set<string> s;
        string prefix = "";
        vector<bool> used(tiles.size(), false);
        combineHelper(s, tiles, prefix, used);
        return s.size();
    }
};