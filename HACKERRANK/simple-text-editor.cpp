#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, temp, k;
  cin >> n;

  stack<string> t;
  string w;

  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if(temp == 1)
    {
      cin >> w;
      if(!t.empty())
        t.push(t.top() + w);
      else
        t.push(w);
    }
    else if(temp == 2)
    {
      cin >> k;
      w = t.top();
      w.erase(w.length() - k);
      t.push(w);
    }
    else if(temp == 3)
    {
      cin >> k;
      w = t.top();
      cout << w[k - 1] << endl;
    }
    else if(temp == 4)
    {
      t.pop();
    }
  }

  return 0;
}