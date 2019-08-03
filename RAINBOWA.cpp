#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int j = 0; j < t; j++) {
	    string ans = "yes";
	    cin >> n;
	    int arr[n];
	    for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
	    if(n <= 12)
	        ans = "no";
	    else {
	        int value_to_check = 1;
	        for(int i = 0; i <= n/2; i++) {
	            if(i >= 1) {
	                if(arr[i] != arr[i - 1])
	                    value_to_check++;
	            }
	            
                if(n % 2 != 0 && (n / 2) == i) {
                    if(arr[i] != 7)
                        ans = "no";
                } 
                else {
                    if(arr[i] != arr[n - i - 1])
    	                ans = "no";
    	            else {
    	                if(arr[i] != value_to_check && arr[i] > 7)
    	                    ans = "no";
    	            }   
                }
	        }
	        if(value_to_check != 7)
	            ans = "no";
	    }
	    
	    cout << ans << endl;
	}
	return 0;
}
