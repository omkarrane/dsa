#include<bits/stdc++.h>

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
    s_int(k);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    int g = ceil((float)n / k);
    for(int i = 0; i < g; i++)
    {
      int l = ((i*k)+k-1);
      if(l > n-1)
        l = n - 1;
      for(int j = l; j >= (i*k); j--)
      {
        printf("%d ", arr[j]);
      }
    }

    printf("\n");
  }

  return 0;
}