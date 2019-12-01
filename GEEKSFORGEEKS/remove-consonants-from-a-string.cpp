#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  cin >> t;
  cin.ignore();

  while(t--)
  {
    string s;
    getline(cin, s);

    bool flag = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u' || s[i] == ' ')
      {
        cout << s[i];
        flag = true;
      }
    }

    if(flag)
      printf("\n");
    else
      printf("No Vowel\n");
  }

  return 0;
}