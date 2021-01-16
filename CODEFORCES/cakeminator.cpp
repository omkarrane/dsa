#include <bits/stdc++.h>

using namespace std;

int main()
{
  int r, c;
  cin >> r >> c;

  set<int> arr1, arr2;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      char ch;
      cin >> ch;
      if (ch == 'S')
      {
        arr1.insert(i);
        arr2.insert(j);
      }
    }
  }

  cout << (r * c) - (arr1.size() * arr2.size()) << "\n";

  return 0;
}