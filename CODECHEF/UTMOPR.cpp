#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, k;
    cin >> n >> k;

    int temp, odd_cnt = 0;
    for (int i = 0; i < n; i++)
    {
      cin >> temp;
      if (temp & 1)
        odd_cnt++;
    }

    if  (k == 1)
    {
      if(odd_cnt % 2 == 0)
        cout << "odd" << endl;
      else
        cout << "even" << endl;
    }
    else
      cout << "even" << endl;
  }

  return 0;
}