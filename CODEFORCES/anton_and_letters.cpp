#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  getline(cin, s);

  int arr[123];
  fill(arr, arr + 123, 0);
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] != '{' && s[i] != '}' && s[i] != ',' && s[i] != ' ')
      arr[(int) s[i]]++;
  }

  int res = 0;
  for (int i = 97; i < 123; i++)
    if (arr[i] != 0)
      res++;

  cout << res << endl;
}