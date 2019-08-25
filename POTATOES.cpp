#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;
  bool sieve[4010];
  fill(begin(sieve), begin(sieve) + 4010, true);
  for(int i = 2; i <= 200; i++)
  {
    if(sieve[i] == true)
    {
      for(int j = i * i; j <= 4000; j = j + i)
      {
        sieve[j] = false;
      }
    }
  }
  while (t--)
  {
    int a, b, c = 0;
    cin >> a >> b;
    for(int i = 0; i <= 3000; i++)
    {
      if(sieve[i] == true && (a + b) < i)
      {
        c = i - a - b;
        break;
      }
    }

    cout << c << endl;
  }

  return 0;
}
