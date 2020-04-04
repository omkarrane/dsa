#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int a, b;
  s_int(a);
  s_int(b);

  for(int i = 0; i < b; i++)
  {
    if((a % 10) != 0)
      --a;
    else
      a /= 10;
  }

  cout << a << "\n";

  return 0;
}