#include<iostream>

using namespace std;
#define m 1000000007
#define ll long long

int main()
{
  int t;
  cin >> t;
  ll n;
  while(t--)
  {
    cin >> n;
    if(n < 3)
    {
      cout << n << endl;
      continue;
    }
    ll res = 1;
    int mul = 1;
    while(n > 0)
    {
      if(n & 1)
        mul = 3;
      else
        mul = 2;
      
      n -= mul;
      res = res % m * mul;
    }
    cout << res << endl;
  }
  return 0;
}