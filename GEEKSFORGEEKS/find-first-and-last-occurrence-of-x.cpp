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

    int arr[n];
    for(int i = 0; i < n; i++)
      s_int(arr[i]);

    s_int(x);
    int* p = (int *)bsearch(&x, arr, n, sizeof(arr[0]), compare);
    if(!p)
    {
      printf("-1\n");
      continue;
    }

    int i = (p - arr);
    int temp1 = i, temp2 = i;
    while(temp1 != 0 && arr[temp1] == arr[temp1-1])
      temp1--;
    
    while(temp2 != n-1 && arr[temp2] == arr[temp2+1])
      temp2++;

    printf("%d %d\n", temp1, temp2);
  }

  return 0;
}