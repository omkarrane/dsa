#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int temp, res[n+1];

  for (int i = 1; i <= n; i++)
  {
    cin >> temp;
    res[temp] = i; 
  }

  for (int i = 1; i <= n; i++)
    cout << res[i] << " ";
  
  cout << endl;

  return 0;
}