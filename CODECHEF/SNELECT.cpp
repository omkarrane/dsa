#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
  int t;
  cin >> t;

  string s;
  while (t--)
  {
    cin >> s;

    int s_count = 0, m_count = 0;
    bool m_ate[102];
    fill(begin(m_ate), begin(m_ate) + 102, false);
    if(s[0] == 'm')
      m_count++;
    else if(s[0] == 's')
      s_count++;

    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == 'm')
      {
        m_count++;
        if (s[i - 1] == 's' && !m_ate[i - 1])
        {
          s_count = max(0, s_count - 1);
          m_ate[i] = true;
        }
      }
      else if (s[i] == 's')
      {
        s_count++;
        if (s[i - 1] == 'm' && !m_ate[i - 1])
        {
          s_count = max(0, s_count - 1);
          m_ate[i] = true;
        }
      }
    }

    if(s_count > m_count)
      cout << "snakes" << endl;
    else if(s_count < m_count)
      cout << "mongooses" << endl;
    else
      cout << "tie" << endl;
  }

  return 0;
}