#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int g = arr[0];
    bool res = false;
    for (int i = 1; i < n; i++)
    {
      g = gcd(g, arr[i]);
      if(g == 1)
      {
        res = true;
        break;
      }
    }

    if(res)
      cout << "0\n";
    else
      cout << "-1\n";
  }

  return 0;
}