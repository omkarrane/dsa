#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-duplicate-number/
class Solution
{
public:
  int findDuplicate(vector<int> &A)
  {
    int fast = A[A[0]], slow = A[0];
    while (fast != slow)
    {
      fast = A[A[fast]];
      slow = A[slow];
    }

    slow = 0;
    while (fast != slow)
    {
      slow = A[slow];
      fast = A[fast];
    }

    return fast;
  }
};