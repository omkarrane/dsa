#include <bits/stdc++.h>

using namespace std;

void reverse_stack(stack<int>);

int main()
{
  int n;
  cin >> n;

  stack<int> st;
  for (int i = 0; i < n; i++)
  {
    int temp;
    cin >> temp;
    st.push(temp);
  }

  reverse_stack(st);
  for (int i = 0; i < n; i++)
  {
    cout << st.top() << " ";
    st.pop();
  }

  cout << "\n";
  return 0;
}

void reverse_stack(stack<int> st)
{
  if (st.empty())
    return;

  int e = st.top();
  st.pop();
  reverse_stack(st);
  st.push(e);
}