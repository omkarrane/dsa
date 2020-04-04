#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int n, temp;
  s_int(n);

  int sum = 0;
  for(int i = 0; i < n; i++)
  {
    s_int(temp);
    sum += temp;
  }

  if(sum == 0)
    cout << "EASY\n";
  else
    cout << "HARD\n";

  return 0;
}