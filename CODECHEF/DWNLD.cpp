#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, k, temp1, temp2;
    cin >> n >> k;
    int price = 0;
    bool b = true;

    for (int i = 0; i < n; i++)
    {
      cin >> temp1 >> temp2;

      if (b)
      {
        int test = k - temp1;
        if (test >= 0)
        {
          k = test;
          continue;
        }
        else
        {
          int j = abs(k - temp1);
          price += (j * temp2);
          b = false;
        }
      }
      else
      {
        price += (temp1 * temp2);
      }
    }

    cout << price << endl;
  }

  return 0;
}