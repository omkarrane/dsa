#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long int n;
  while (cin >> n && n > 0)
  {
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
      cin >> arr[i];

    stack<long long int> st;
    long long int i = 0, maxArea = 0, area = 0;
    while (i < n)
    {
      if (st.empty() || arr[st.top()] <= arr[i])
      {
        st.push(i);
        i++;
      }
      else
      {
        long long int top = st.top();
        st.pop();
        if (st.empty())
          area = arr[top] * i;
        else
          area = arr[top] * (i - st.top() - 1);

        if (maxArea < area)
          maxArea = area;
      }
    }

    while (!st.empty())
    {
      long long int top = st.top();
      st.pop();
      if (st.empty())
        area = arr[top] * i;
      else
        area = arr[top] * (i - st.top() - 1);

      if (maxArea < area)
        maxArea = area;
    }

    cout << maxArea << endl;
  }
  return 0;
}
