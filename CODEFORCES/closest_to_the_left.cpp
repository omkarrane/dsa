#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < k; i++)
  {
    int target;
    cin >> target;

    int high = n - 1;
    int low = 0;
    int ans = -1;
    while (low <= high)
    {
      int mid = low + (high - low) / 2;
      if (arr[mid] <= target)
      {
        ans = mid;
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }

    cout << ans + 1 << "\n";
  }

  return 0;
}
