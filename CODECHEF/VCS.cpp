#include<iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, m, k, temp;
    cin >> n >> m >> k;
    int arr[n + 1] = {0};
    for(int  i = 0; i < m; i++)
    {
      cin >> temp;
      arr[temp]++;
    }

    for(int  i = 0; i < k; i++)
    {
      cin >> temp;
      arr[temp]++;
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++)
    {
      if(arr[i] == 0) cnt1++;
      else if(arr[i] == 2) cnt2++;
    }

    cout << cnt2 << ' ' << cnt1 << endl;
  }
}
