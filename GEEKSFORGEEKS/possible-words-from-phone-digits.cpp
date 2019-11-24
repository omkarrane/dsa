#include <bits/stdc++.h>

using namespace std;
#define s_int(num) scanf("%d", &num)

int main()
{
  int t;
  s_int(t);

  string s[10];
  s[2] = "abc";
  s[3] = "def";
  s[4] = "ghi";
  s[5] = "jkl";
  s[6] = "mno";
  s[7] = "pqrs";
  s[8] = "tuv";
  s[9] = "wxyz";

  while (t--)
  {
    int n;
    s_int(n);

    int arr[n];
    for (int i = 0; i < n; i++)
      s_int(arr[i]);

    vector<string> res;
    for (int i = 0; i < s[arr[0]].size(); i++)
      res.push_back(string(1, s[arr[0]].at(i)));

    for (int i = 1; i < n; i++)
    {
      string to_merge2 = s[arr[i]]; // DEF
      vector<string> temp;
      for (int j = 0; j < res.size(); j++)
      {
        string to_merge1 = res[j]; // A
        for (int k = 0; k < to_merge2.size(); k++)
        {
          temp.push_back(to_merge1 + to_merge2[k]);
        }
      }
      res = temp;
    }

    for (int i = 0; i < res.size(); i++)
      printf("%s ", res[i].c_str());

    printf("\n");
  }

  return 0;
}