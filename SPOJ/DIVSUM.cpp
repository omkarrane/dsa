#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, temp;
  cin >> n;

  while(n--)
  {
    cin >> temp;
    int res = 0;

    if(temp == 1)
    {
      cout << "0" << endl;
      continue;
    }

    for(int i = 1; i*i <= temp; i++)
    {
      if((temp % i) == 0)
      {
        if(i == (temp / i) || i == 1)
          res += i;
        else
          res += i + (temp / i);
      }
    }

    cout << res << endl;
  }

  return 0;
}