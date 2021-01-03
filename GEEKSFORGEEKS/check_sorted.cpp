#include <bits/stdc++.h>

using namespace std;

int check_sorted(int *, int);

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  if (check_sorted(arr, n - 1))
    cout << "YES\n";
  else
    cout << "NO\n";

  return 0;
}

int check_sorted(int arr[], int i)
{
  if (i == 0)
    return 1;
  
  if (arr[i - 1] > arr[i])
    return 0;

  return check_sorted(arr, --i);
}