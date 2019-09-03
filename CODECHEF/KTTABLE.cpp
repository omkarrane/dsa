#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, cnt = 0;
    cin >> n;
    long arr_n[n+1], arr_b[n+1];
    arr_n[0] = 0;
    arr_b[0] = 0;
    
    for(int i = 1; i <= n; i++)
      cin >> arr_n[i];

    for(int i = 1; i <= n; i++)
      cin >> arr_b[i];

    for(int i = 1; i <= n; i++)
      if((arr_n[i] - arr_n[i - 1]) >= arr_b[i])
        cnt++;

    cout << cnt << endl;
  }
}