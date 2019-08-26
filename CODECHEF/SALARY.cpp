#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int j = 0; j < t; j++) {
	    cin >> n;
	    int arr[n], sum = 0;
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	        sum += arr[i];
	    }
	    int min = arr[0];
	    for(int i = 0; i < n; i++) {
	        if(arr[i] < min)
	            min = arr[i];
	    }
	    cout << (sum-(n*min)) << endl;
	}
	return 0;
}
