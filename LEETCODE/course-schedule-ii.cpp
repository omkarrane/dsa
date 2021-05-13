#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/course-schedule-ii/
/**
  * This is a problem of finding a topological order of the courses.
  * There are 2 ways we can do that.
  * We can either do a dfs traversal of the courses for this. 
    * For finding a cycle, we color the nodes in 3 types - 1,2,3
    * 1 is for un-visited node.
    * 2 is for currently in-process node.
    * 3 is for visited node
  * At any point if we find a node that is in-process, it means that there is a cycle.
  * Else the order received is the answer.
 */
class Solution {
public:
    vector<int> ans;
    map<int, vector<int>> graph;
    vector<int> visited;
    bool isPossible;
    
    void dfs(int node) {
        visited[node] = 2;
        vector<int> adj = graph[node];
        
        for (int i = 0; i < adj.size(); i++) {
            if (visited[adj[i]] == 1)
                dfs(adj[i]);
            else if (visited[adj[i]] == 2)
                isPossible = false;
        }
        
        ans.push_back(node);
        visited[node] = 3;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        int n = numCourses;
        isPossible = true;
        ans = vector<int>();
        graph = map<int, vector<int>>();
        visited = vector<int>(n);
        
        for (int i = 0; i < n; i++) {
            graph[i] = vector<int>();
            visited[i] = 1;            
        }
        
        for (int i = 0; i < p.size(); i++) {
            graph[p[i][0]].push_back(p[i][1]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 1)
                dfs(i);
        }
        
        if (isPossible)
            return ans;
        return vector<int>();
    }
};