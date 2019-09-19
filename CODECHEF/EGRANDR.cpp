#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, marks;
    float avg = 0.0;
    cin >> n;

    bool f_grade = false, full_grade = false;
    for(int i = 0; i < n; i++)
    {
      cin >> marks;
      if(marks <= 2)
        f_grade = true;
      else if(marks == 5)
        full_grade = true;

      avg = ((avg * i) + marks) / (i + 1);
    }

    if(!f_grade && full_grade && avg >= 4.0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}