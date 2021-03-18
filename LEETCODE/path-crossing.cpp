#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/path-crossing/
/**
 * use set of pair to store every point visited per step
 * when we encounter a previously visited point, return true
*/ 
class Solution {
public:
    bool isPathCrossing(string path) {
        int up = 0, right = 0;
        set<pair<int, int>> points;
        points.insert({0, 0});
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == 'N') {
                up++;   
            }
            else if (path[i] == 'S') {
                up--;
            }
            else if (path[i] == 'E') {
                right++;   
            }
            else {
                right--;   
            }
            
            if (points.find({up, right}) != points.end())
                    return true;
            
            points.insert({up, right});
        }
        
        return false;
    }
};