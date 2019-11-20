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

    int num, res = INT_MAX, res_elem = INT_MIN;
    for(int i = 0; i < n; i++)
    {
      s_int(num);
      int temp = abs(num - k);
      if(res == temp)
      {
        if(num > res_elem)
          res_elem = num;
      }
      else if(res > temp)
      {
        res = temp;
        res_elem = num;
      }
    }

    printf("%d\n", res_elem);
  }

  return 0;
}