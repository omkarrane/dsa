#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while (t--)
  {
    int n;
    s_int(n);

    int arr[n];
    for (int i = 0; i < n; i++)
      s_int(arr[i]);

    int i = 1, j = n-2, s1 = arr[0], s2 = arr[n-1];
    bool flag = false;
    while (i <= j)
    {
      if(s1 == s2 && i == j)
      {
        flag = true;
        break;
      }

      if(s1 < s2)
      {
        s1 += arr[i];
        i++;
      }
      else
      {
        s2 += arr[j];
        j--;
      }
    }

    if (n == 1)
      printf("1\n");
    else
    {
      if (flag)
        printf("%d\n", i + 1);
      else
        printf("-1\n");
    }
  }

  return 0;
}