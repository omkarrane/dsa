#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  string s;
  while (t--)
  {
    cin >> s;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if(s[i] == '0') cnt0++;
      else if(s[i] == '1') cnt1++;
    }

    if(s.length() == 1)
      cout << "Yes" << endl;
    else if (cnt1 == 0 || cnt0 == 0)
      cout << "No" << endl;
    else if(cnt1 > 1 && cnt0 > 1)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
}