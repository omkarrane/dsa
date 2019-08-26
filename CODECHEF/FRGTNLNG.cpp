#include <iostream>
#include <cstring>
#include <set> 
using namespace std;

int main() {
	int t;
	cin >> t;
	for(int j = 0; j < t; j++) {
	    int n, k;
	    cin >> n >> k;
	    string arr_n[n];
	    
	    for(int i = 0; i < n; i++)
	        cin >> arr_n[i];
	    
	    set<string> phrases;
	    set<string>::iterator it1;
	    for(int w = 0; w < k; w++) {
	        int l;
    	    cin >> l;
    	    string temp;
    	    for(int i = 0; i < l; i++) {
    	        cin >> temp;
    	        phrases.insert(temp);
    	    }
	    }
	    
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for (it1 = phrases.begin(); it1!=phrases.end(); ++it1) {
                if(*it1 == arr_n[i]) {
                    flag = true;
                    break;
                }
            }
            if(flag)
                cout << "YES ";
            else
                cout << "NO ";
        }

	    cout << endl;
	}
	return 0;
}
