#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int n, k;
  s_int(n);
  s_int(k);

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    s_int(arr[i]);
  }

  int count = 0, comp = arr[k - 1];

  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= comp && arr[i] != 0)
      count++;
  }

  cout << count << "\n";

  return 0;
}