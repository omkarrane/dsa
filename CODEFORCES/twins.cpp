#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  int half = 0, temp;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr.push_back(temp);
    half += arr[i];
  }
  half = floor(half / 2);
  half++;
  sort(arr.begin(), arr.end());
  int coins = 0, curr_total = 0;
  while (curr_total < half)
  {
    vector<int>::iterator upper = upper_bound(arr.begin(), arr.end(), half - curr_total);
    if ((upper - arr.begin()) >= arr.size())
    {
      curr_total += arr[upper - arr.begin() - 1];
      arr.erase(upper - 1);
    }
    else
    {
      curr_total += arr[upper - arr.begin()];
      arr.erase(upper);
    }
    coins++;
  }

  cout << coins << endl;
  return 0;
}