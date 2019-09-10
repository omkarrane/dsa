#include<bits/stdc++.h>

using namespace std;

int main()
{
  int l, b;
  cin >> l >> b;

  long peri = 2 * (l + b);
  long area = l * b;
  
  if(peri > area)
    cout << "Peri" << endl << peri << endl;
  else if(peri < area)
    cout << "Area" << endl << area << endl;
  else
    cout << "Eq" << endl << peri << endl;

  return 0;
}