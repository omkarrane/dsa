#include<bits/stdc++.h>
using namespace std;

string convert_to_roman(int);

int main()
{
  int n;
  cin >> n;
  cout << convert_to_roman(n) << "\n";

  return 0;
}

string convert_to_roman(int n)
{
    string str = "";
    int l[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string m[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    
    // Your code here
    while (n > 0)
    {
        for (int i = 0; i < 14; i++)
        {
            if (i == 13 || n < l[i])
            {
                str += m[i - 1];
                n -= l[i - 1];
                break;
            }
        }
    }
    
    return str;
}
