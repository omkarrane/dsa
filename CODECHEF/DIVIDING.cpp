#include<iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  unsigned long long int sum = 0ULL;
  unsigned long long int for_result = (n * (n + 1ULL) / 2);
  for(long i = 0; i < n; i++)
  {
    long int temp;
    cin >> temp;
    sum += temp;
  }
  if(for_result == sum)
    cout << "YES";
  else
    cout << "NO";
  
  return 0;
}
