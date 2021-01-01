#include <bits/stdc++.h>

using namespace std;

int factorial(int);

int main()
{
  int n;
  cin >> n;
  cout << factorial(n) << "\n";
  return 0;
}

int factorial(int n)
{
  if (n < 0)
    return -1;
  else if (n == 0 || n == 1)
    return 1;
    
  return n * factorial(n - 1);
}