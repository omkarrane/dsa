#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    int a, b;
    long long int c = 0LL;
    cin >> a >> b;
    vector<int> v1, v2;
    while(a != 0)
    {
      v1.push_back(a % 10);
      a /= 10;
    }
    while(b != 0)
    {
      v2.push_back(b % 10);
      b /= 10;
    }

    while(v1.size() < v2.size())
      v1.push_back(0);
    while(v2.size() < v1.size())
      v2.push_back(0);

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    for(int i = 0; i < v1.size(); i++)
    {
      c = (c * 10) + (((v1[i] % 10) + (v2[i] % 10)) % 10);
    }

    cout << c << endl;
  }

  return 0;
}