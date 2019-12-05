#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)
#define NUM 10000002

int main()
{
  int t;
  s_int(t);

  bitset<NUM> sieve;
  for (int i = 2; i * i <= NUM; i++)
  {
    if (sieve[i] == 0)
    {
      for (int j = i * i; j <= NUM; j += i)
        sieve[j] = 1;
    }
  }

  vector<int> arr;
  for (int i = 5; i <= NUM; i++)
    if (sieve[i] == 0 && sieve[i - 2] == 0)
      arr.push_back(i);

  while (t--)
  {
    int n;
    s_int(n);

    long res = upper_bound(arr.begin(), arr.end(), n) - arr.begin();
    printf("%d\n", res);
  }

  return 0;
}