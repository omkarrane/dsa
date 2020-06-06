#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;

  transform(a.begin(), a.end(), a.begin(), ::tolower);
  transform(b.begin(), b.end(), b.begin(), ::tolower);

  int res = a.compare(b);
  if (res < 0)
    cout << "-1\n";
  else if (res > 0)
    cout << "1\n";
  else
    cout << "0\n";

  return 0;
}