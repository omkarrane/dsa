#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++)
      cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
      int len = 1;
      for (int j = i; j < n - 1; j++)
      {
        if (arr[j + 1] > 0 && arr[j] < 0)
          len++;
        else if (arr[j + 1] < 0 && arr[j] > 0)
          len++;
        else
          break;
      }
      if(len > 1)
      {
        for(int k = len; k > 0; k--)
          cout << k << " ";
        i += len - 1;
      }
      else
        cout << len << " ";
    }
    cout << endl;
  }
  return 0;
}