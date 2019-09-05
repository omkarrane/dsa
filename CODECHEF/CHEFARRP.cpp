#include<iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++)
      cin >> arr[i];

    long long int cnt = 0;
    for(int i = 0; i < n; i++)
    {
      cnt++;
      long long int sum = arr[i], prod = arr[i];
      for(int j = i+1; j < n; j++)
      {
        sum += arr[j];
        prod *= arr[j];
        if(sum == prod) cnt++;
      }
    }

    cout << cnt << endl;
  }
}