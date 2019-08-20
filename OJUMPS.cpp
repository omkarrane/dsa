#include <iostream>

using namespace std;

int main()
{
  long a, t;
  bool flag = false;
  cin >> a;
  if (a <= 6)
  {
    if (a == 0 || a == 1 || a == 3 || a == 6)
      flag = true;
  }
  else
  {
    if (a % 6 == 0)
      t = 6;
    else if (a % 3 == 0)
      t = 3;
    else
      t = 1;

    if ((a - t) % 6 == 0)
      flag = true;
  }

  if (flag)
    cout << "yes";
  else
    cout << "no";
    
  return 0;
}
