#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int j = 0; j < t; j++) {
		int n, temp;
		long c, sum = 0;
		cin >> n >> c;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			sum += (long)temp;
		}
		if(sum <= c)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
