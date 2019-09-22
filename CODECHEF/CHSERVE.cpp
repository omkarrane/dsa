#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    long p1, p2, k;
    cin >> p1 >> p2 >> k;

    long total = p1 + p2;

    long rem = total % (2 * k);

    if(rem < k)
      cout << "CHEF" << endl;
    else
      cout << "COOK" << endl;
  }

  return 0;
}