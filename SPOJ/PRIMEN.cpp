#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  int arr[1010] = {0};

  for(int i = 2; i*i < 1010; i++)
  {
    if(arr[i] == 0)
    {
      for(int j = i*i; j < 1010; j += i)
        arr[j] = 1;
    }
  }

  while(t--)
  {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
      if(arr[i] == 0)
        cout << i << endl;
    }

    cout << endl;
  }

  return 0;
}