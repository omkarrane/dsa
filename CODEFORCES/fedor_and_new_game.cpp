#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, m, k;
  cin >> n >> m >> k;

  vector<long long int> arr;
  for (int i = 0; i <= m; i++)
  {
    long long int temp;
    cin >> temp;

    arr.push_back(temp);
  }

  long long int f = arr[m];
  int res = 0;
  for (int i = 0; i < m; i++)
  {
    long long int cpy1 = f, cpy2 = arr[i];
    int count = 0;
    while (cpy1 || cpy2) {
      if ((cpy1 & 1) != (cpy2 & 1))
        count++;

      cpy1 >>= 1;
      cpy2 >>= 1;
      
      if (count > k)
        break;
    }
    if (count <= k)
      res++;
  }

  cout << res << endl;
  return 0;
}