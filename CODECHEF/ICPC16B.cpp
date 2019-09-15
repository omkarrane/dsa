#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    int n, temp;
    cin >> n;

    long int a, one = 0, m_one = 0, zero = 0, others = 0;
    for(int i = 0; i < n; i++)
    {
      cin >> a;
      if(a == 1)
        one++;
      else if(a == -1)
        m_one++;
      else if(a == 0)
        zero++;
      else
        others++;
    }

    if(others > 1)
      cout << "no" << endl;
    else if(m_one > 1 && one == 0)
      cout << "no" << endl;
    else if(m_one > 0 && others > 0)
      cout << "no" << endl;
    else
      cout << "yes" << endl;
  }

  return 0;
}