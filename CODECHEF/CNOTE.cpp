#include<iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int x, y, k, n, pg_left, temp_c, temp_p;
	bool flag = false;
	for(int j = 0; j < t; j++) {
		cin >> x >> y >> k >> n;
		pg_left = x - y;
		flag = false;
		for(int i = 0; i < n; i++) {
			cin >> temp_p >> temp_c;
			if(temp_c <= k && temp_p >= pg_left) {
				flag = true;
			}
		}
		if(flag)
			cout << "LuckyChef" << endl;
		else
			cout << "UnluckyChef" << endl;
	}
	return 0;
}
