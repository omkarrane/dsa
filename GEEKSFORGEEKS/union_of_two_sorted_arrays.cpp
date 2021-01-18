#include <bits/stdc++.h>
using namespace std;

vector<int> find_union(int[], int[], int, int);

int main()
{
  int n, m;
  cin >> n >> m;
  int arr1[n], arr2[m];
  for (int i = 0; i < n; i++)
    cin >> arr1[i];

  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  vector<int> arr3 = find_union(arr1, arr2, n, m);
  for (int i : arr3)
    cout << i << " ";
  cout << "\n";
  return 0;
}

vector<int> find_union(int arr1[], int arr2[], int n, int m)
{
  vector<int> arr3;
  int i = 0, j = 0;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      if (!arr3.empty() && arr3.back() == arr1[i])
        i++;
      else
        arr3.push_back(arr1[i++]);
    }
    else if (arr2[j] < arr1[i])
    {
      if (!arr3.empty() && arr3.back() == arr2[j])
        j++;
      else
        arr3.push_back(arr2[j++]);
    }
  }

  while (i < n)
  {
    if (!arr3.empty() && arr3.back() == arr1[i])
      i++;
    else
      arr3.push_back(arr1[i++]);
  }

  while (j < m)
  {
    if (!arr3.empty() && arr3.back() == arr2[j])
      j++;
    else
      arr3.push_back(arr2[j++]);
  }

  return arr3;
}
