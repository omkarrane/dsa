#include <bits/stdc++.h>
using namespace std;

int remove_duplicates(int[], int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int m = remove_duplicates(arr, n);
  for (int i = 0; i < m; i++)
    cout << arr[i] << " ";
  cout << "\n";
  return 0;
}

int remove_duplicates(int arr[], int n)
{
  int j = 0;
  for (int i = 1; i < n; i++)
  {
    if (arr[j] != arr[i])
      j++;
    swap(arr[i], arr[j]);
  }

  return j + 1;
}
