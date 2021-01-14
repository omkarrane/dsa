#include <bits/stdc++.h>
using namespace std;

void rotate_array(int[], int, int);
void rotate_array_2(int[], int, int);

int main()
{
  int n, d;
  cin >> n >> d;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  rotate_array_2(arr, n, d);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << "\n";
  return 0;
}

void rotate_array(int arr[], int n, int d)
{
  int arr2[n], curr = 0;
  d = d % n;
  for (int i = 0; i < n; i++)
  {
    if (i < n - d)
      arr2[i] = arr[i + d];
    else
    {
      arr2[i] = arr[curr++];
    }
  }

  copy(arr2 + 0, arr2 + n, arr);
}

void rotate_array_2(int arr[], int n, int d)
{
  reverse(arr, arr + d);
  reverse(arr + d, arr + n);
  reverse(arr, arr + n);
}
