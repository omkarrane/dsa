#include <bits/stdc++.h>
using namespace std;

int longest_subarray_of_even_odd(int[], int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << longest_subarray_of_even_odd(arr, n) << "\n";
  return 0;
}

int longest_subarray_of_even_odd(int arr[], int n)
{
  int curr = 1, max = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[i-1] % 2 == 0 && arr[i] % 2 != 0)
      curr++;
    else if (arr[i-1] % 2 != 0 && arr[i] % 2 == 0)
      curr++;
    else
      curr = 1;

    if (curr > max)
      max = curr;
  }
  
  return max;
}
