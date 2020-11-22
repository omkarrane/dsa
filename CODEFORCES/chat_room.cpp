#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int curr = 0;
  char c[] = {'h', 'e', 'l', 'l', 'o'};

  for (int i = 0; i < s.size(); i++)
  {
    if (c[curr] == s[i])
      curr++;

    if (curr == 5)
      break;
  }

  if (curr == 5)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0; 
}