#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int sqr(int x) {
  return x * x;
}

float dist(int x1, int y1, int x2, int y2)
{
  int powx = sqr(x2 - x1);
  int powy = sqr(y2 - y1);
  float result = powx + powy;
  return result;
}

int main() {
  long t, cnt = 0L;
  cin >> t;
  while(t--)
  {
    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    float a, b, c;
    a = dist(x1, y1, x2, y2);
    b = dist(x2, y2, x3, y3);
    c = dist(x1, y1, x3, y3);
    
    if((a + b) == c || (a + c) == b || (b + c) == a)
      cnt++;
    
  }

  cout << cnt << endl;
  
  return 0;
}
