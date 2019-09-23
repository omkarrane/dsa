#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    char a = 'n', b = 'n', c = 'n';
    int n;
    cin >> n;

    if ((360 % n) == 0)
      a = 'y';

    if (n <= 360)
      b = 'y';

    int sum = n / 2 * (n + 1);
    if(sum <= 360)
      c = 'y';

    cout << a << " " << b << " " << c << endl;
  }

  return 0;
}