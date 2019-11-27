#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

bool check_adjacent(int num)
{
  vector<int> arr;
  while(num != 0)
  {
    arr.push_back(num % 10);
    num /= 10;
  }

  if(arr.size() == 1)
    return false;

  for(int i = 1; i < arr.size(); i++)
  {
    if(abs(arr[i-1] - arr[i]) != 1)
      return false;
  }

  return true;
}

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
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
      s_int(arr[i]);
      if(arr[i] < k && check_adjacent(arr[i]))
      {
        printf("%d ", arr[i]);
        flag = true;
      }
    }

    if(flag)
      printf("\n");
    else
      printf("-1\n");
  }

  return 0;
}