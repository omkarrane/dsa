#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    int n, b;
    cin >> n >> b;

    int w, h, p, max_area = 0;
    bool res = false;
    for(int i = 0; i < n; i++)
    {
      cin >> w >> h >> p;
      if(b >= p)
      {
        int temp = w * h;
        if(max_area < temp)
        {
          max_area = temp;
          res = true;
        }
      }
    }

    if(res)
      cout << max_area << endl;
    else
      cout << "no tablet" << endl;
  }  

  return 0;
}