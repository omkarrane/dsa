#include<bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n, d;
    s_int(n);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    s_int(d);

    d %= n;

    for(int i = d; i < n; i++)
      printf("%d ", arr[i]);
    
    for(int i = 0; i < d; i++)
      printf("%d ", arr[i]);

    printf("\n");
  }

  return 0;
}