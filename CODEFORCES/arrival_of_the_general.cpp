#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int max = 0, min = n - 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > arr[max])
      max = i;

    if (arr[i] <= arr[min])
      min = i;
  }

  int res = 0;
  res += max;
  if (max > min)
    min++;

  res += n - min - 1;

  cout << res << endl;

  return 0;
}