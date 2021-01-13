#include <bits/stdc++.h>
using namespace std;

vector<int> leaders_in_array(int[], int);

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> arr2 = leaders_in_array(arr, n);
  for (int i = 0; i < arr2.size(); i++)
    cout << arr2[i] << " ";
  return 0;
}

vector<int> leaders_in_array(int arr[], int n)
{
  vector<int> result;
  int max = INT_MIN;
  for (int i = n - 1; i >= 0; i--)
  {
    if (max <= arr[i])
    {
      max = arr[i];
      result.push_back(arr[i]);
    }
  }
  reverse(result.begin(), result.end());
  return result;
}
