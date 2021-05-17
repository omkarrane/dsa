#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule/
/**
  * This is a problem to find if there is a cycle in the graph generated or not.
  * We can do this via a DFS algorithm.
 */
class Solution {
public:
    vector<int> visited;
    unordered_map<int, vector<int>> graph;
    bool isPossible;
    
    void dfs(int node) {
        visited[node] = 1;
        vector<int> adj = graph[node];
        for (int i = 0; i < adj.size(); i++) {
            if (visited[adj[i]] == 1) {
                isPossible = false;
                break;
            }
            else if (visited[adj[i]] == 0)
                dfs(adj[i]);
        }
        
        visited[node] = 2;
    }
    
    bool canFinish(int n, vector<vector<int>>& p) {
        visited = vector<int>(n);
        isPossible = true;
        
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
            visited[i] = 0;
        }
        
        for (int i = 0; i < p.size(); i++) {
            graph[p[i][1]].push_back(p[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0)
                dfs(i);
        }
        
        return isPossible;
    }
};