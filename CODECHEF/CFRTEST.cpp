#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, temp;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++)
    {
      cin >> temp;
      s.insert(temp);
    }

    cout << s.size() << endl;
  }
  return 0;
}