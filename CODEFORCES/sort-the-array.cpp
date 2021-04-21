#include <bits/stdc++.h>
using namespace std;

/**
 * we can just find the segment which is not sorted first, then reverse this segment and check if it sorts the array
 * TC - O(n)
 */
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> arr(n);
  bool found = false;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int start = 0, end = n - 1;
  for (int i = 1; i < n; i++) {
    if (arr[i - 1] > arr[i])
    {
      if (!found)
        start = i - 1;
      found = true;
    }
    else if (arr[i - 1] < arr[i] && found)
    {
      end = i - 1;
      break;
    }
  }

  if (found)
    reverse(arr.begin() + start, arr.begin() + end + 1);
  else
    end = 0;
    
  bool sorted = true;
  for (int i = 1; i < n; i++)
  {
    if (arr[i - 1] > arr[i])
    {
      sorted = false;
      break;
    }
  }

  if (sorted)
  {
    if (end == -1)
      end = n - 1;
    cout << "yes\n" << start + 1 << " " << end + 1 << "\n";
  }
  else
  {
    cout << "no\n";
  }

  return 0;
}
