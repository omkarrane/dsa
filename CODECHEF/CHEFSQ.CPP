#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long n, s;
    cin >> n;
    long arr[n];
    for (long i = 0; i < n; i++)
      cin >> arr[i];

    cin >> s;
    long seq[s];
    for (long i = 0; i < s; i++)
      cin >> seq[i];

    long j = 0;
    for (long i = 0; i < n; i++)
    {
      if(arr[i] == seq[j])
      {
        j++;
        if(j == s) 
          break;
      }
    }

    if(j == s)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}