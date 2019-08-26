#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long n, ans;
    cin >> n;
    ans = n - 1LL;
    for (int i = 2; i * i <= n; i++)
    {
      long long div = n / i;
      if (n % i == 0)
        if (ans > abs(div - i))
          ans = abs(div - i);
    }

    cout << ans << endl;
  }
}
