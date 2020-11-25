#include <bits/stdc++.h>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;

  int n1, n2, n3, n4, n5, n6;
  n1 = a + b * c;
  n2 = a * (b + c);
  n3 = a * b * c;
  n4 = (a + b) * c;
  n5 = a + b + c;
  n6 = a * b + c;

  cout << max({n1, n2, n3, n4, n5, n6}) << endl;
}