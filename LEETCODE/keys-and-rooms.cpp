#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    vector<bool> visited;
    unordered_map<int, vector<int>> graph;
    
    void dfs(int room) {
        if (visited[room])
            return;
        
        visited[room] = true;
        vector<int> adj = graph[room];
        for (int i = 0; i < adj.size(); i++)
            dfs(adj[i]);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        visited = vector<bool>(n, false);
        
        for (int i = 0; i < n; i++)
            graph[i] = vector<int>();
        
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                graph[i].push_back(rooms[i][j]);                
            }
        }
        
        dfs(0);
        for (int i = 0; i < n; i++) 
            if (!visited[i])
                return false;
        
        return true;
    }
};