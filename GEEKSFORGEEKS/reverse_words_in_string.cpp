#include <bits/stdc++.h>
using namespace std;

string reverse_words(string);

int main()
{
  string str;
  getline(cin, str);

  cout << reverse_words(str) << "\n";
  return 0;
}

string reverse_words(string str)
{
  string result;
  int last = str.length() - 1;
  for (int i = str.length() - 1; i >= 0; i--)
  {
    if (str[i] == '.')
    {
      if (last == str.length() - 1)
        result.append(str.substr(i+1, last - i) + ".");
      else
        result.append(str.substr(i+1, last - i - 1) + ".");
      last = i;
    }
    else if (i == 0)
    {
      if (last == str.length() - 1)
        return str;
      result.append(str.substr(i, last - i));
    }
  }

  return result;
}
