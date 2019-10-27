#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int n, temp, num, max = 0;
  cin >> n;

  // Refer to SPOJ/HISTOGRA.cpp

  stack<pair<int, int>> s;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    if(temp == 1)
    {
      cin >> num;
      if(num > max)
        max = num;
      s.push(make_pair(num, max));
    }
    else if(temp == 2)
    {
      s.pop();
      if(s.size() > 0)
        max = s.top().second;
      else
        max = 0;
    }
    else if(temp == 3)
      cout << s.top().second << endl;
  }
  

  return 0;
}
