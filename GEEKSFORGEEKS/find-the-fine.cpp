#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while (t--)
  {
    int n, d;
    s_int(n);
    s_int(d);

    int arr[n];
    for (int i = 0; i < n; i++)
      s_int(arr[i]);

    int fines[n];
    for (int i = 0; i < n; i++)
      s_int(fines[i]);

    long long int fine = 0;

    for (int i = 0; i < n; i++)
    {
      if (d % 2 != 0)
      {
        if(arr[i] % 2 == 0)
          fine += fines[i];
      }
      else
      {
        if(arr[i] % 2 != 0)
          fine += fines[i];
      }
    }

    printf("%d\n", fine);
  }

  return 0;
}