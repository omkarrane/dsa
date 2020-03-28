#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  int x = 0, y = 0, z = 0, temp = 0;
  for(int i = 0; i < t; i++)
  {
    s_int(temp);
    x += temp;
    s_int(temp);
    y += temp;
    s_int(temp);
    z += temp;
  }

  if(x == 0 && y == 0 && z == 0)
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}