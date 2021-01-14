#include <iostream>
using namespace std;
int remainderWith7(string);

int main()
{
  // your code goes here
  int t;
  cin >> t;
  while (t--)
  {
    string n;
    cin >> n;

    cout << remainderWith7(n) << endl;
  }
  return 0;
} // } Driver Code Ends

/*You are required to complete this method */
int remainderWith7(string str)
{
  int result = 0, t, curr = 0;
  int s[] = {1, 3, 2};
  bool f = false;
  for (int i = str.length() - 1; i >= 0; i--)
  {
    t = (str[i] - '0') * s[curr % 3];
    if (f)
      t = -t;
    if (curr % 3 == 2)
      f = !f;

    result += t;
    curr++;
  }

  int m = result % 7;
  if (m < 0)
    return 7 + m;
  return m;
}