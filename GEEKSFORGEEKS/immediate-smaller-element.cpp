#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
    int n;
    scanf("%d", &n);

    int prev, next;
    scanf("%d", &prev);

    if (n == 1)
    {
      printf("-1\n");
      continue;
    }

    for (int i = 0; i < n - 1; i++)
    {
      scanf("%d", &next);
      if (next < prev)
        printf("%d ", next);
      else
        printf("-1 ");

      prev = next;
    }
    printf("-1\n");
  }

  return 0;
}