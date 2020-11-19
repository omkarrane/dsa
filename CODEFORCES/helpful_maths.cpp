#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;

  vector<int> arr;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] != '+')
      arr.push_back((int) s[i] - 48);
  }
  sort(arr.begin(), arr.end());
  if (arr.size() == 1)
    cout << s;
  else
  {
    cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
      cout << "+" << arr[i];
  }
  
  cout << endl;

  return 0;
}
