#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  int k;
  cin >> k;
  for (int i = 0; i < k; i++)
  {
    int target1, target2;
    cin >> target1 >> target2;

    int high = n - 1;
    int low = 0;
    int ans1 = n;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] >= target1)
      {
        ans1 = mid;
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    low = 0;
    high = n - 1;
    int ans2 = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] <= target2)
      {
        ans2 = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    if (ans1 >= n)
      cout << "0 ";
    else
      cout << ans2 - ans1 + 1 << " ";
  }

  cout << "\n";
  return 0;
}
