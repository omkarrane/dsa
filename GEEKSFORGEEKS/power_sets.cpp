#include <bits/stdc++.h>
using namespace std;

vector<string> power_set(string);

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string S;
    cin >> S;
    vector<string> vec = power_set(S);
    for (string s : vec)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}

void all_subsets(vector<string> &arr, string curr, string og, int k)
{
  arr.push_back(curr);
  if (k == og.length())
  {
    return;
  }

  for (int i = k; i < og.length(); i++)
  {
    curr += og[i];
    all_subsets(arr, curr, og, i + 1);
    curr = curr.substr(0, curr.size() - 1);
  }
}

vector<string> power_set(string str)
{
  vector<string> arr;
  all_subsets(arr, "", str, 0);
  sort(arr.begin(), arr.end());
  return arr;
}
