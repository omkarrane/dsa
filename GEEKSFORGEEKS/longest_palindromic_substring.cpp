#include <bits/stdc++.h>
using namespace std;

string longest_palindromic_substring(string);

int main()
{
  string str;
  getline(cin, str);

  cout << longest_palindromic_substring(str) << "\n";
  return 0;
}

bool is_palindrome(string s1)
{
  string s2 = s1;
  reverse(s2.begin(), s2.end());
  return s1 == s2;
}

string longest_palindromic_substring(string str)
{
  if (str.length() == 1)
    return str;

  int len = 0;
  string res;

  for (int i = 1; i < str.length(); i++)
  {
    int i1 = i - 1;
    int i2 = i + 1;
    while (str[i1] == str[i2] && i1 >= 0 && i2 < str.length())
    {
      if ((i2 - i1 + 1) > len)
      {
        res = str.substr(i1, (i2 - i1 + 1));
        len = res.length();
      }
      i1--;
      i2++;
    }

    i1 = i - 1;
    i2 = i;
    while (str[i1] == str[i2] && i1 >= 0 && i2 < str.length())
    {
      if ((i2 - i1 + 1) > len)
      {
        res = str.substr(i1, (i2 - i1 + 1));
        len = res.length();
      }
      i1--;
      i2++;
    }
  }

  if (res.empty())
    res = str[0];
  return res;
}
