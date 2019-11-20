#include <bits/stdc++.h>

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

    sort(arr, arr+n);

    int temp = n-1;
    if(n % 2 == 0)
      temp--;

    for(int i = temp; i >= 0; i -= 2)
      printf("%d ", arr[i]);

    for(int i = 1; i < n; i += 2)
      printf("%d ", arr[i]);

    printf("\n");
  }

  return 0;
}