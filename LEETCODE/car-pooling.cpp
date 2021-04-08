#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/car-pooling/
/**
 * we can have an array or a map to store the number of passengers that got in and out
 * then once we have this, we start the trip and add/subtract based on passengers got in or out
 * at each step we check if the passengers exceed capacity
 */
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int road[1001] = {0};
        
        for (int i = 0; i < trips.size(); i++) {
            road[trips[i][1]] += trips[i][0];
            road[trips[i][2]] -= trips[i][0];
        }
        
        int passengers = 0;
        for (int i = 0; i < 1001; i++) {
            passengers += road[i];
            
            if (passengers > capacity)
                return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> start, end;
        int last = INT_MIN;
        for (int i = 0; i < trips.size(); i++) {
            last = max(last, trips[i][2]);
            
            if (start.find(trips[i][1]) == start.end())
                start[trips[i][1]] = 0;
            start[trips[i][1]] += trips[i][0];
            
            if (end.find(trips[i][2]) == end.end())
                end[trips[i][2]] = 0;
            end[trips[i][2]] += trips[i][0];
        }
        
        int passengers = 0;
        for (int i = 1; i < last; i++) {
            if (start.find(i) != start.end())
                passengers += start[i];
            
            if (end.find(i) != end.end())
                passengers -= end[i];
            
            if (passengers > capacity)
                return false;
        }
        
        return true;
    }
};