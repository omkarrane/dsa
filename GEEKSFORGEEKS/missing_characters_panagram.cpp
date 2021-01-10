#include <bits/stdc++.h>
using namespace std;

string missing_characters_panagram(string);

int main()
{
  string str;
  getline(cin, str);

  cout << missing_characters_panagram(str) << "\n";
  return 0;
}

string missing_characters_panagram(string str)
{
  string result;
  transform(str.begin(), str.end(), str.begin(), ::tolower);
  int arr[26];
  fill(arr, arr + 26, 0);

  for (int i = 0; i < str.length(); i++)
    arr[str[i] - 'a']++;

  for (int i = 0; i < 26; i++)
    if (arr[i] == 0)
      result += char(i + 'a');
  
  return result;
}
