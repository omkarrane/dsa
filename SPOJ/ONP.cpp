#include <bits/stdc++.h>
using namespace std;

/**
 * use a stack for storing the operators and brackets
 * key point is to store the operators and brackets in an ascending priority fashion 
 * so that when they are popped the highest priority operator is the first to get popped
 */
bool isOp(char a)
{
  return a == '+' || a == '-' || a == '/' || a == '*' || a == '^';
}

int priority(char a)
{
  if (a == '+' || a == '-')
    return 1;
  else if (a == '/' || a == '*')
    return 2;
  else if (a == '^')
    return 3;
  return -1;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    stack<char> op;
    string var;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
        op.push(s[i]);
      else if (isOp(s[i]))
      {
        while (!op.empty() && priority(op.top()) >= priority(s[i]))
        {
          var.push_back(op.top());
          op.pop();
        }

        op.push(s[i]);
      }
      else if (s[i] == ')')
      {
        while (!op.empty() && op.top() != '(')
        {
          var.push_back(op.top());
          op.pop();
        }
        op.pop();
      }
      else
      {
        var.push_back(s[i]);
      }
    }

    cout << var << "\n";
  }
  return 0;
}
