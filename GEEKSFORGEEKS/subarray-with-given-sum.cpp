#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n, s;
    s_int(n);
    s_int(s);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    int left = 0, right = 0, sum = 0;
    bool flag = false;
    while(left <= right && right <= n)
    {
      if(sum == s)
      {
        flag = true;
        break;
      }
      if(sum < s)
      {
        sum += arr[right];
        right++;
      }
      else if(sum > s)
      {
        sum -= arr[left];
        left++;
      }
    }

    if(flag)
      printf("%d %d\n", left+1, right);
    else
      printf("-1\n");
  }

  return 0;
}