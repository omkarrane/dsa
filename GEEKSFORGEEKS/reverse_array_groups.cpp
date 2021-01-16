#include <bits/stdc++.h>
using namespace std;

void reverse_array_in_groups(vector<int> &, int, int);

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    arr.push_back(temp);
  }

  int k;
  cin >> k;

  reverse_array_in_groups(arr, n, k);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}

void reverse_array_in_groups(vector<int> &arr, int n, int k)
{
  for (int i = 0; i < arr.size(); i += k)
  {
    if (i + k < arr.size())
      for (int j = 0; j < k / 2; j++)
        swap(arr[i + j], arr[i + k - j - 1]);
    else
    {
      for (int j = i; j < (i + arr.size()) / 2; j++)
        swap(arr[j], arr[arr.size() + i - j - 1]); 
    }
  }
}
