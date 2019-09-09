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
    int arr_l[n], arr_r[n];
    for(int i = 0; i < n; i++)
      cin >> arr_l[i];

    for(int i = 0; i < n; i++)
      cin >> arr_r[i];

    int max_val = 0, index, max_r = 0;
    for(int i = 0; i < n; i++)
    {
      int temp = arr_l[i] * arr_r[i];
      if(temp > max_val)
      {
        max_val = temp;
        max_r = arr_r[i];
        index = i;
      }
      else if(temp == max_val && arr_r[i] > max_r)
      {
        max_val = temp;
        max_r = arr_r[i];
        index = i;
      }
    }

    cout << (index + 1) << endl;
  }
  return 0;
}