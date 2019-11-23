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
    map<int, bool> map;
    for(int i = 0; i < n; i++)
    {
      s_int(arr[i]);
      arr[i] *= arr[i];
      map.insert(pair<int, bool>(arr[i], true));
    }

    bool flag = false;
    for(int i = 0; i < n-1; i++)
    {
      for(int j = i+1; j < n; j++)
      {
        int to_find = arr[i] + arr[j];
        auto res = map.find(to_find);
        if(res != map.end())
        {
          printf("Yes\n");
          flag = true;
          break;
        }
      }

      if(flag)
      {
        break;
      }
    }

    if(!flag)
    {
      printf("No\n");
    }
  }

  return 0;
}