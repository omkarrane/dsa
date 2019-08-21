#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while(t--) 
  {
    set<long> s;
    long n, temp;
    cin >> n;
    for(long i = 0; i < n; i++)
    {
      cin >> temp;
      s.insert(temp);
    }

    cout << s.size() << endl;
  }

  return 0;
}
