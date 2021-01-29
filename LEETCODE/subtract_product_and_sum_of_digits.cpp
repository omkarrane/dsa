#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
class Solution
{
public:
  int subtractProductAndSum(int n)
  {
    int prod = 1, sum = 0;
    while (n != 0)
    {
      int i = n % 10;
      n /= 10;
      prod *= i;
      sum += i;
    }

    return prod - sum;
  }
};