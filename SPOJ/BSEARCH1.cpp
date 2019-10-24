#include<stdio.h>

using namespace std;

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);

  int arr[n];
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for(int i = 0; i < k; i++)
  {
    int find;
    scanf("%d", &find);

    int low = 0, high = n - 1;
    int mid;
    int res = -1;

    while(low <= high)
    {
      mid = low + (high - low) / 2;
      if(arr[mid] == find)
      {
        res = mid;
        break;
      }
      else if(find < arr[mid])
        high = mid - 1;
      else if(find > arr[mid])
        low = mid + 1;
    }

    printf("%d\n", res);
  }

  return 0;
}