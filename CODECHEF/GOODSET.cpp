#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, n;
  cin >> t;

  while(t--)
  {
    cin >> n;

    int i = 1, length = 1;
    while(length <= n)
    {
      cout << i << " ";
      i += 2;
      length++;
    }
    
    cout << endl;
  }

  return 0;
}