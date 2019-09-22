#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    string a, b, c;
    cin >> a >> b >> c;

    if(
      (a[0] == 'l' && b[0] == 'l' && b[1] == 'l') ||
      (a[1] == 'l' && b[1] == 'l' && b[2] == 'l') ||
      (b[0] == 'l' && c[0] == 'l' && c[1] == 'l') ||
      (b[1] == 'l' && c[1] == 'l' && c[2] == 'l')
    )
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }

  return 0;
}