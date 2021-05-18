#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-city-scheduling/
/**
  * For having the minimum cost, we need to select 'n' people giving maximum profit for travelling to city A.
  * This can be done via sorting w.r.t. cost(B) - cost(A).
  * After selecting first n people who will travel to city A, we select the rest for travelling to city B.
  * This way greedily selecting the first n people giving maximum profit if travelled to city A, we obtain the global minimum cost.
  * This also works the other way round, selecting the first n people giving maximum profit if travelled to city B.
 */
class Solution {
public:
    struct compare {
        bool operator() (vector<int> &a, vector<int> &b) {
            return (a[1] - a[0]) < (b[1] - b[0]);
        }
    };
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare());
        
        int total = 0;
        int n = costs.size();
        for (int i = 0; i < n / 2; i++)
            total += costs[i][1] + costs[i + n / 2][0];
        
        return total;
    }
};