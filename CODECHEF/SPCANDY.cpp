#include <iostream>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--) {
    long long int n, k, teacher = 0, student = 0;
    cin >> n >> k;
    if(n == 0)
    {
      cout << "0 0" << endl;
      continue;
    }
    else if(k == 0)
    {
      cout << "0 " << n << endl;
      continue;
    }
    teacher = n % k;
    student = n / k;
    cout << student << " " << teacher << endl;
  }

  return 0;
}
