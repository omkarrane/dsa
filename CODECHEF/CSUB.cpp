#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int w = 0; w < t; w++) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                sum += 1 + count++;
            }
        }
        cout << sum << endl;
    }
	return 0;
}
