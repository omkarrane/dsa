#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-number-of-teams/
class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    int ans = 0;
    for (int i = 1; i < rating.size() - 1; i++)
    {
      int leftLess = 0, leftGreater = 0, rightLess = 0, rightGreater = 0;
      for (int j = 0; j < i; j++)
      {
        if (rating[j] < rating[i])
          leftLess++;
        else if (rating[j] > rating[i])
          leftGreater++;
      }
      for (int j = i + 1; j < rating.size(); j++)
      {
        if (rating[j] > rating[i])
          rightGreater++;
        else if (rating[j] < rating[i])
          rightLess++;
      }

      ans += (leftLess * rightGreater) + (leftGreater * rightLess);
    }

    return ans;
  }
};