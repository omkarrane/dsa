#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main () {
  int n;
  s_int(n);

  if(n < 3)
    cout << "NO\n";
  else if(n % 2 == 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}