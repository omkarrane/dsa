#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int a, b, c, d, arr[10000] = {0};
    cin >> a >> b >> c >> d;
    arr[a]++;
    arr[b]++;
    arr[c]++;
    arr[d]++;

    bool res = true;
    for(int i = 0; i < 10000; i++)
      if(arr[i] & 1)
        res = false;

    if(res)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}