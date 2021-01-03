#include <bits/stdc++.h>

using namespace std;

int string_to_int(string, int, int);

int main()
{
  string s;
  getline(cin, s);

  cout << string_to_int(s, 0, 0) << "\n";
  return 0;
}

int string_to_int(string s, int i, int num)
{
  if (s.length() == i)
    return num;

  num += (s.at(s.length() - i - 1) - '0') * pow(10, i);
  return string_to_int(s, ++i, num);
}
