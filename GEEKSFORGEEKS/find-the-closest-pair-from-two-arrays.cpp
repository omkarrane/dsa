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
    s_int(m);

    int arr1[n], arr2[m];
    for(int i = 0; i < n; i++)
      s_int(arr1[i]);

    for(int i = 0; i < m; i++)
      s_int(arr2[i]);

    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    int x;
    s_int(x);

    int min = INT_MAX, start = 0, end = 0;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        int temp = abs((arr1[i] + arr2[j]) - x);
        if(min > temp)
        {
          min = temp;
          start = i;
          end = j;
        }
      }
    }

    printf("%d %d\n", arr1[start], arr2[end]);
  }

  return 0;
}