#include <bits/stdc++.h>
using namespace std;

int longest_substring(string);

int main()
{
  string str;
  getline(cin, str);

  cout << longest_substring(str) << "\n";
  return 0;
}

int longest_substring(string str)
{
  if (str.length() == 1)
    return 1;

  int arr[26], len = 0, tmp = 0, start = 0;
  int last[26];
  fill(arr, arr + 26, 0);
  fill(last, last + 26, 0);
  for (int i = 0; i < str.length(); i++)
  {
    if (arr[str[i] - 'a'] == 0)
    {
      tmp++;
      if (tmp > len)
      {
        len = tmp;
      }
      arr[str[i] - 'a']++;
      last[str[i] - 'a'] = i;
    }
    else
    {
      int t = tmp - last[str[i] - 'a'];
      for (int j = last[str[i] - 'a']; j >= 0; j--)
      {
        arr[str[j] - 'a'] = 0;
        last[str[j] - 'a'] = 0;
      }
      tmp = t;
      last[str[i] - 'a'] = i;
      arr[str[i] - 'a']++;
    }
  }
  return len;
}
