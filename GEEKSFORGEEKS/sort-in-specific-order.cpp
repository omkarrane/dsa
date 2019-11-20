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

    vector<int> v1, v2;
    for(int i = 0; i < n; i++)
      if(arr[i] % 2 == 0)
        v1.push_back(arr[i]);
      else
        v2.push_back(arr[i]);

    for(int i = v2.size()-1; i >= 0; i--)
      printf("%d ", v2[i]);
    
    for(int i = 0; i < v1.size(); i++)
      printf("%d ", v1[i]);

    printf("\n");
  }
}