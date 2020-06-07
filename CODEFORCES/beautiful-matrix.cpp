#include <bits/stdc++.h>

using namespace std;
#define si(num) scanf("%d", &num)

int main()
{
  int temp = 0, xpos, ypos;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      si(temp);
      if (temp == 1)
      {
        xpos = i;
        ypos = j;
      }
    }
  }

  printf("%d\n", abs(2 - xpos) + abs(2 - ypos));

  return 0;
}