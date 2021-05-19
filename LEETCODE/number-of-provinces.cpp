#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-provinces/
/**
  * This can be solved by finding the number of connected components.
  * We can find the connected components using disjoint union find algorithm.
  * Once done, count the number of cities having same city as parent.
 */
class Solution {
public:
    vector<int> dsu;
    
    int find(int u) {
        while (u != dsu[u])
            u = dsu[u];
        
        return u;
    }
    
    void join(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        
        if (pu == pv)
            return;
        
        dsu[pu] = pv;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        dsu = vector<int>(n);
        for (int i = 0; i < n; i++)
            dsu[i] = i;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1)
                    join(i, j);
            }
        }
        
        int cities = 0;
        for (int i = 0; i < n; i++) {
            if (i == find(i))
                cities++;
        }
        
        return cities;
    }
};