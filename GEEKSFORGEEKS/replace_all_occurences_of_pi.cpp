#include <bits/stdc++.h>

using namespace std;

string replace_pi(string, int);

int main()
{
  string s;
  getline(cin, s);

  cout << replace_pi(s, 0) << "\n";
  return 0;
}

string replace_pi(string s, int i)
{
  if (i > s.length() - 2)
    return s;

  if (s[i] == 'p' && s[i + 1] == 'i')
  {
    s.replace(i, 2, "3.14");
    return replace_pi(s, i + 2);
  }
  else
    return replace_pi(s, ++i);
}