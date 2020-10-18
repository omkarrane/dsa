#include <bits/stdc++.h>

#define s_int(num) scanf("%d", &num)
using namespace std;
int bin_search(int[], int, int);

int main()
{
  int t;
  s_int(t);
  while (t--)
  {
    int n, q;
    s_int(n);
    s_int(q);

    int arr[n];
    for (int i = 0; i < n; i++)
      s_int(arr[i]);

    for (int i = 0; i < q; i++)
    {
      int to_search;
      s_int(to_search);
      int index = bin_search(arr, n, to_search);
      printf("%d ", index);
    }
    printf("\n");
  }
  return 0;
}

// My Solution
int bin_search(int arr[], int n, int q) {
  int low = 0, high = n, mid;
  while (low < high) {
    mid = (high + low) / 2;
    if (q <= arr[mid]) {
      high = mid;
    }
    else {
      low = mid + 1;
    }
  }

  return high;
}

// GEEKSFORGEEKS
int bin_search2(int arr[], int n, int x)
{
  int low = 0, high = n - 1, res = -1;
  while (low <= high)
  {
    // Normal Binary Search Logic
    int mid = (low + high) / 2;
    if (arr[mid] > x)
      high = mid - 1;
    else if (arr[mid] < x)
      low = mid + 1;

    // If arr[mid] is same as x, we
    // update res and move to the left
    // half.
    else
    {
      res = mid;
      high = mid - 1;
    }
  }
  return res;
}