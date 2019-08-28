#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int a, res = 1;
    long long int b;
    cin >> a >> b;
    if (a == 0)
      cout << '0' << endl;
    else if(a == 1)
      cout << '1' << endl;
    else
    {
      if (b == 0)
        cout << '1' << endl;
      else
      {
        while (b > 0)
        {
          if (b & 1) {
            res = res * a;
            res = res % 10;
          }
          a = a * a;
          a = a % 10;
          b >>= 1;
        }
        cout << res << endl;
      }
    }
  }

  return 0;
}