#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s)
{
  bool res = true;
  stack<int> t;

  for (int i = 0; i < s.length(); i++)
  {
    if(s[i] == '(')
      t.push(1);
    else if(s[i] == '{')
      t.push(2);
    else if(s[i] == '[')
      t.push(3);
    else if(s[i] == ')')
    {
      if(t.empty() || t.top() != 1)
      {
        res = false;
        break;
      }
      else
        t.pop();
    }
    else if(s[i] == '}')
    {
      if(t.empty() || t.top() != 2)
      {
        res = false;
        break;
      }
      else
        t.pop();
    }
    else if(s[i] == ']')
    {
      if(t.empty() || t.top() != 3)
      {
        res = false;
        break;
      }
      else
        t.pop();
    }
  }

  if(res && t.empty())
    return "YES";
  else
    return "NO";
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int t_itr = 0; t_itr < t; t_itr++)
  {
    string s;
    getline(cin, s);

    string result = isBalanced(s);

    fout << result << "\n";
  }

  fout.close();

  return 0;
}