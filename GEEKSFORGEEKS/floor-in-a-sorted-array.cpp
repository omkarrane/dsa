#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int compare(const void* ap, const void* bp) 
{ 
    // Typecasting 
    const int* a = (int*)ap; 
    const int* b = (int*)bp; 
  
    if (*a < *b) 
        return -1; 
    else if (*a > *b) 
        return 1; 
    else
        return 0; 
}

int main()
{
  int t;
  s_int(t);

  while(t--)
  {
    int n, x;
    s_int(n);
    s_int(x);

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    bool flag = false;
    while(x >= arr[0])
    {
      if(!binary_search(arr, arr+n, x))
        x--;
      else
      {
        flag = true;
        break;
      } 
    }

    int* p = (int *)bsearch(&x, arr, n, sizeof(arr[0]), compare);
    if(flag)
      printf("%d\n", p-arr);
    else
      printf("-1\n");
  }

  return 0;
}