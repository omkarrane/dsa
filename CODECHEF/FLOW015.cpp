#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    int y, leap = 0;
    cin >> y;
    int res;

    for(int i = 1900; i < y; i++)
    {
      if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
        leap++;
    }

    res = (y + leap - 1900) % 7;

    res = res % 7;
    if(res == 6)
      cout << "sunday" << endl;
    else if(res == 0)
      cout << "monday" << endl;
    else if(res == 1)
      cout << "tuesday" << endl;
    else if(res == 2)
      cout << "wednesday" << endl;
    else if(res == 3)
      cout << "thursday" << endl;
    else if(res == 4)
      cout << "friday" << endl;
    else if(res == 5)
      cout << "saturday" << endl;
  }

  return 0;
}