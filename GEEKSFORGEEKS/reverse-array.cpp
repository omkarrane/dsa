#include<bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n;
    s_int(n);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    for(int i = n-1; i >= 0; i--)
      printf("%d ", arr[i]);

    printf("\n");
  }

  return 0;
}