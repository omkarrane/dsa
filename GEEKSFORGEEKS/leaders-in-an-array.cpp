#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  scanf("%d", &t);

  while(t--)
  {
    int n, max = 0;
    scanf("%d", &n);

    int arr[n];
    vector<int> res;
    for(int i = 0; i < n; i++)
      scanf("%d", &arr[i]);

    for(int i = (n-1); i >= 0; i--)
    {
      if(arr[i] >= max)
      {
        max = arr[i];
        res.push_back(arr[i]);
      }
    }

    for(int i = (res.size()-1); i >= 0; i--)
    {
      printf("%d ", res[i]);
    }
    printf("\n");
  }

  return 0;
}