#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(vector<int>);

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }

  cout << max_sum_subarray(arr) << "\n";
  return 0;
}

int max_sum_subarray(vector<int> arr)
{
  int sum = arr[0], res = arr[0];
  for (int i = 1; i < arr.size(); i++)
  {
    sum = max(arr[i], sum + arr[i]);
    res = max(res, sum);
  }

  return res;
}
