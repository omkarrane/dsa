#include <bits/stdc++.h>
using namespace std;

bool are_isomorphic(string, string);

int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  if (are_isomorphic(s1, s2))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

bool are_isomorphic(string s1, string s2)
{
  if (s1.length() != s2.length())
    return false;

  int a1[26], a2[26];
  fill(a1, a1 + 26, 0);
  fill(a2, a2 + 26, 0);
  a1[s1[0] - 'a']++;
  a2[s2[0] - 'a']++;
  for (int i = 1; i < s1.length(); i++)
  {
    if (((s1[i] == s1[i - 1]) && (s2[i] == s2[i - 1]) ||
         (s1[i] != s1[i - 1]) && (s2[i] != s2[i - 1])) &&
        a1[s1[i] - 'a'] == a2[s2[i] - 'a'])
    {
      a1[s1[i] - 'a']++;
      a2[s2[i] - 'a']++;
      continue;
    }
    else
      return false;
  }

  return true;
}
