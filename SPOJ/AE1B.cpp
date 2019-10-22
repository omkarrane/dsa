#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, k, s;
  cin >> n >> k >> s;

  vector<int> arr;
  for(int i = 0; i <n; i++)
  {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end(), greater<int>());

  int screws_needed = k * s;
  int curr = 0, result = 0;
  while(curr < screws_needed)
  {
    curr += arr[result];
    result++;
  }

  cout << result << endl;

  return 0;
}