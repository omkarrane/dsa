#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
    vector<int> getNoOfSmallerElements(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < k)
                    a++;
                if (matrix[i][j] < k + 1)
                    b++;
            }
        }

        vector<int> ans = {a, b};
        return ans;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        k--;
        int low = INT_MAX, high = INT_MIN;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                low = min(low, matrix[i][j]);
                high = max(high, matrix[i][j]);
            }
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<int> midK = getNoOfSmallerElements(matrix, mid);

            if (midK[0] <= k && midK[1] > k && midK[0] != midK[1])
                return mid;

            if (midK[0] <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1;
    }
};