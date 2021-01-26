#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-the-matrix-diagonally/
class Solution
{
public:
  vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
  {
    int j = 0;
    int i = 0;
    while (j < mat[i].size())
    {
      int k = i;
      int l = j;
      vector<int> arr;
      while (k < mat.size() && l < mat[i].size())
        arr.push_back(mat[k++][l++]);
      sort(arr.begin(), arr.end());

      int curr = 0;
      int p = i;
      int q = j;
      while (p < mat.size() && q < mat[i].size())
        mat[p++][q++] = arr[curr++];
      j++;
    }

    i = 1;
    j = 0;
    while (i < mat.size())
    {
      int k = i;
      int l = j;
      vector<int> arr;
      while (k < mat.size() && l < mat[i].size())
        arr.push_back(mat[k++][l++]);
      sort(arr.begin(), arr.end());

      int curr = 0;
      int p = i;
      int q = j;
      while (p < mat.size() && q < mat[i].size())
        mat[p++][q++] = arr[curr++];
      i++;
    }

    return mat;
  }
};