#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    string s[n];
    for (int i = 0; i < n; i++)
      cin >> s[i];

    string res = "";
    bool flag = true;
    for(int j = 0; j < s[0].size(); j++)
    {
      char check = s[0][j];
      bool check_flag = true;
      for(int i = 1; i < n; i++)
      {
        if(j > s[i].size())
        {
          flag = false;
          break;
        }

        if(s[i][j] != check)
          check_flag = false;
      }

      if(!flag)
        break;

      if(check_flag)
        res += check;
      else
        break;
    }

    if(res.size() == 0)
      printf("-1\n");
    else
      printf("%s\n", res.c_str());
  }

  return 0;
}