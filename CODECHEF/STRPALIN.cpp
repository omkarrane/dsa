#include<bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while(t--)
  {
    string s1, s2;
    cin >> s1 >> s2;

    int arr1[27] = {0}, arr2[27] = {0};
    for(int i = 0; i < s1.length(); i++)
      arr1[(int)s1[i] - 97]++;

    for(int i = 0; i < s2.length(); i++)
      arr2[(int)s2[i] - 97]++;

    bool res = false;
    for(int i = 0; i < 27; i++)
    {
      if(arr1[i] > 0 && arr2[i] > 0)
      {
        res = true;
        break;
      }
    }

    if(res)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}