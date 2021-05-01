#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<long long>> arr(n + 1, vector<long long>(3));
  for (int i = 1; i <= n; i++)
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

  for (int i = 1; i <= n; i++)
  {
    long long prev = 0;

    prev = max(arr[i - 1][1], arr[i - 1][2]);
    arr[i][0] += prev;

    prev = max(arr[i - 1][0], arr[i - 1][2]);
    arr[i][1] += prev;

    prev = max(arr[i - 1][0], arr[i - 1][1]);
    arr[i][2] += prev;
  }

  long long ans = max(arr[n][0], arr[n][1]);
  ans = max(ans, arr[n][2]);

  cout << ans << "\n";

  return 0;
}