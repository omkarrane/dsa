#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n, m;
    s_int(n);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    s_int(m);

    sort(arr, arr+n);
    int min = arr[n-1] - arr[0];
    for(int i = 0; i <= (n-m); i++)
    {
      int diff = arr[i+m-1] - arr[i];
      if(min > diff)
        min = diff;
    }

    printf("%d\n", min);
  }

  return 0;
}