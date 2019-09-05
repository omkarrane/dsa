#include<iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, x, y, res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
      cin >> x >> y;
      res ^= i;
    }

    cout << res << endl;
  }
}