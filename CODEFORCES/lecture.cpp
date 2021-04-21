#include <bits/stdc++.h>
using namespace std;

/**
 * this can be solved using hashing
 */
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  map<string, string> m1;

  string s1, s2;
  for (int i = 0; i < m; i++)
  {
    cin >> s1 >> s2;
    m1[s1] = s2;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> s1;
    if (s1.size() <= m1[s1].size())
      cout << s1 << " ";
    else
      cout << m1[s1] << " ";
  }

  cout << "\n";
  return 0;
}
