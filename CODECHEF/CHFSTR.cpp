#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--)
  {
    string s1;
    cin >> s1;

    vector<int> arr;
    int curr = 1;
    for (int i = 1; i < s1.size(); i++)
    {
      if (s1[i] == s1[i - 1])
        curr++;
      else
      {
        arr.push_back(curr);
        curr = 1;
      }
    }
    arr.push_back(curr);
    vector<int> arr2 = arr;
    sort(arr2.begin(), arr2.end());
    int cost = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      cost += abs(arr2[i] - arr[i]);
    }

    cout << cost / 2 << "\n";
  }

  return 0;
}

/**
4
aabbcccdeffffggghhhhhii
aaaa
abbcccdd
aaaabbbccd
*/