#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int n, x = 0;
  s_int(n);

  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    s.erase(remove(s.begin(), s.end(), 'X'), s.end());

    if (s == "++")
      x++;
    else if(s == "--")
      x--;
  }

  cout << x << "\n";

  return 0;
}