#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/plus-one/
class Solution
{
public:
  vector<int> plusOne(vector<int> &digits)
  {
    int carry = 0;
    int len = digits.size();
    int curr = len - 1;
    digits[curr]++;
    if (digits[curr] > 9)
    {
      int temp = digits[curr];
      digits[curr] %= 10 + carry;
      carry = temp / 10;
      curr--;
      while (curr >= 0 && carry != 0)
      {
        digits[curr] += carry;
        temp = digits[curr];
        digits[curr] %= 10;
        carry = temp / 10;
        curr--;
      }
      while (carry != 0)
      {
        digits.insert(digits.begin(), carry % 10);
        carry /= 10;
      }
    }

    return digits;
  }
};