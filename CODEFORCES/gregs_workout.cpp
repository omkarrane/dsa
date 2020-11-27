#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, temp;
  cin >> n;

  int arr[3];
  fill(arr, arr + 3, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr[i % 3] += temp;
  }

  if (arr[0] > arr[1] && arr[0] > arr[2])
    cout << "chest\n";
  else if (arr[1] > arr[0] && arr[1] > arr[2])
    cout << "biceps\n";
  else if (arr[2] > arr[0] && arr[2] > arr[1])
    cout << "back\n";

  return 0;
}