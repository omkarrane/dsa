#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while (t--)
  {
    int n, temp;
    s_int(n);

    int arr[1201] = {0};
    for (int i = 0; i < n; i++)
    {
      s_int(temp);
      arr[temp] = 1;
    }

    bool flag = false;
    for (int i = 1200; i >= 0; i--)
    {
      if (arr[i] == 1)
      {
        if (flag)
        {
          printf("%d\n", i);
          break;
        }
        flag = true;
      }
    }
  }

  return 0;
}