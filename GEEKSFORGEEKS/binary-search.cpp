#include <bits/stdc++.h>
using namespace std;
int bin_search(int A[], int left, int right, int k);
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
      cin >> a[i];
    int key;
    cin >> key;
    int found = bin_search(a, 0, N - 1, key);
    cout << found << endl;
  }
}

/*This is a function problem.You only need to complete the function given below*/
/*You need to complete this function */
int bin_search(int arr[], int left, int right, int k)
{
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (arr[mid] == k)
      return mid;
    else if (arr[mid] < k)
      left = mid + 1;
    else if (arr[mid > k])
      right = mid - 1;
  }

  return -1;
}