#include <bits/stdc++.h>

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
    for(int i = 0; i < n; ++i)
      s_int(arr[i]);

    deque<int> q;
    int i;
    for(int i = 0; i < k; i++)
    {
      while((!q.empty()) && arr[i] >= arr[q.back()])
        q.pop_back();

      q.push_back(i);
    }
    for(; i < n; i++)
    {
      printf("%d ", arr[q.front()]);

      while((!q.empty()) && q.front() <= (i - k))
        q.pop_front();

      while((!q.empty()) && arr[i] >= arr[q.back()])
        q.pop_back();
      
      q.push_back(i);
    }

    printf("%d\n", arr[q.front()]);
  }
  
  return 0;
}
