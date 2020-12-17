#include <bits/stdc++.h>

#define lli long long int

using namespace std;
unordered_map<int, lli> dp;

lli fact(int num) {
  if (num <= 1)
    return 1;
  
  if (dp[num])
    return dp[num];
  return dp[num] = num * fact(num - 1);
}

int main()
{
  int n, m;
  cin >> n >> m;

  lli mi = 0;
  int k = n / m;
  int p = n % m;

  if (p == 0)
    mi = (k * (k - 1) / 2) * m;
    // mi = (fact(k) / (2 * fact(k - 2))) * m;
  else {
    int arr[m];
    fill(arr, arr + m, 1);
    for (int i = 0; i < (n - m); i++)
      arr[i % m]++;

    for (int i = 0; i < m; i++)
      mi += arr[i] * (arr[i] - 1) / 2;
      // mi += (fact(arr[i]) / (2 * fact(arr[i] - 2)));
  }
  cout << mi << " ";
  mi = (n - m + 1) * (n - m) / 2;
  // mi = fact(n - m + 1) / (2 * fact(n - m + 1 - 2));
  cout << mi << endl;

  return 0;  
}