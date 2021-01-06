#include <bits/stdc++.h>
using namespace std;

bool is_rotated_by_2(string, string);

int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  
  if (is_rotated_by_2(s1, s2))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

bool is_rotated_by_2(string s1, string s2)
{
  if (s1.length() != s2.length())
    return false;

  if (s1.length() == 1)
    return s1 == s2;
  
  int len = s2.length();
  string cpy1 = s2.substr(2) + s2[0] + s2[1];
  string cpy2 = "";
  cpy2.push_back(s2[len - 2]);
  cpy2.push_back(s2[len - 1]);
  cpy2 += s2.substr(0, len - 2);

  if (cpy1 == s1 || cpy2 == s1)
    return true;

  return false;
}
