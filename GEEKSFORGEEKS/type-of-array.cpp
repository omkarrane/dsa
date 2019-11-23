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
    int max = INT_MIN, max_index = 0, min = INT_MAX, min_index = 0, val = 0;

    for(int i = 0; i < n; i++)
    {
      s_int(arr[i]);
      if(max < arr[i])
      {
        max = arr[i];
        max_index = i;
      }
      if(min > arr[i])
      {
        min = arr[i];
        min_index = i;
      }
    }

    if(min_index == 0 && max_index == n-1)
      val = 1;
    else if(min_index == n-1 && max_index == 0)
      val = 2;
    else if(arr[0] < arr[n-1] && min_index < max_index)
      val = 3;
    else
      val = 4;

    printf("%d %d\n", max, val);
  }

  return 0;
}