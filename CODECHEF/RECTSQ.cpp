#include <iostream>

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
    int a, b;
    cin >> a >> b;
    int g = gcd(a, b);
    int result = int(a / g) * int(b / g);
    cout << result << endl;
  }
  return 0;
}