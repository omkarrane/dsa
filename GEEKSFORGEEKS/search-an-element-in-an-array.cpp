#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n, k;
    s_int(n);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    s_int(k);

    int index = -1;
    for(int i = 0; i < n; i++)
    {
      if(arr[i] == k)
      {
        index = i;
        break;
      }
    }

    printf("%d\n", index);
  }

  return 0;
}