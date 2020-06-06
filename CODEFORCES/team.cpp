#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int n, count = 0;
  s_int(n);
  while (n--)
  {
    int a, b, c;
    s_int(a);
    s_int(b);
    s_int(c);
    if ((a + b + c) >= 2)
      count++;
  }

  cout << count << "\n";

  return 0;
}