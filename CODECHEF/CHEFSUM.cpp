#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
      cin >> arr[i];

    int min_elem = INT_MAX, index = 1;
    for(int i = 0; i < n; i++)
    {
      if(arr[i] < min_elem)
      {
        min_elem = arr[i];
        index = i;
      }
    }
    
    cout << (index + 1) << endl;
  }

  return 0;
}