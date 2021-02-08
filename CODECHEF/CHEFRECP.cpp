#include <bits/stdc++.h>
using namespace std;

void solve()
{
  int n, temp;
  cin >> n;
  map<int, int> m;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if (m.find(temp) == m.end())
      m[temp] = 0;
    
    m[temp]++;
    arr.push_back(temp);
  }

  for (int i = 1; i < arr.size(); i++)
  {
    while (i < arr.size() && arr[i] == arr[i - 1])
      i++;

    for (int j = i; j < arr.size(); j++)
    {
      if (arr[i - 1] == arr[j] || m[arr[i - 1]] == m[arr[j]])
      {
        cout << "NO\n";
        return;
      }
    }
  }

  cout << "YES\n";
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    solve();
  }

  return 0;
}