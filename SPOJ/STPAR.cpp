#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n && n != 0) {
		stack<int> st;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		
		int toCheck = 1, i = 0;
		string ans = "yes";
		
		while(i < n) {
		    while(!st.empty() && toCheck == st.top()) {
		        st.pop();
		        toCheck++;
		    }
			    
			if(toCheck != arr[i]) {
				if(st.empty()) 
					st.push(arr[i++]);
				else if(!st.empty() && arr[i] > st.top()) {
					ans = "no";
					break;
				}
				else {
					st.push(arr[i++]);
				}
			}
			else {
				toCheck++;
				i++;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
