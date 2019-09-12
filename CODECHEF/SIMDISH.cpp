#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    map<string, int> mp;

    string temp;
    for(int i = 0; i < 4; i++)
    {
      cin >> temp;
      mp.insert(pair<string, int>(temp, 0));
    }

    for(int i = 0; i < 4; i++)
    {
      cin >> temp;
      map<string, int>::iterator itr = mp.find(temp);
      if(itr != mp.end())
        mp[temp]++;
    }

    int cnt = 0;
    for(auto i : mp)
    {
      if(i.second > 0)
      {
        cnt++;
      }
    }

    if(cnt >= 2)
      cout << "similar" << endl;
    else
      cout << "dissimilar" << endl;
  }

  return 0;
}