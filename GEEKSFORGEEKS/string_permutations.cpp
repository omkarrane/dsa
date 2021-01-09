#include <bits/stdc++.h>
using namespace std;

vector<string> permutation(string);

int main()
{
  int T;
  cin >> T;
  while(T--)
  {
    string S;
    cin >> S;
    vector<string> vec = permutation(S);
    for (string s : vec)
      cout << s << " ";
    cout << endl;
  }

  return 0;
}

void all_permutations(vector<string> & arr, string curr, string og, bool* marked)
{
  if (curr.length() == og.length())
  {
    arr.push_back(curr);
    return;
  }

  for (int i = 0; i < og.length(); i++)
  {
    if (marked[i] == true)
      continue;
    marked[i] = true;
    curr += og[i];
    all_permutations(arr, curr, og, marked);
    marked[i] = false;
    curr = curr.substr(0, curr.size() - 1);
  }
}

vector<string> permutation(string str)
{
  vector<string> arr;
  bool marked[str.length()];
  fill(marked, marked + str.length(), false);
  all_permutations(arr, "", str, marked);
  sort(arr.begin(), arr.end());
  return arr;
}
