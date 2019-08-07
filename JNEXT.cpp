#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long n, temp;
        cin >> n;
        vector<int> arr;
        for(long i = 0; i < n; i++) {
            cin >> temp;
            arr.push_back(temp);
        }
        
        bool flag = false;
        for(long i = arr.size() - 1; i > 0; i--) {
            if(arr[i] > arr[i - 1]) {
				int min = i;
				for(int z = i + 1; z < arr.size(); z++)
					if(arr[min] > arr[z] && arr[i - 1] < arr[z]) min = z;
				
                swap(arr[min], arr[i - 1]);
                sort(arr.begin() + i, arr.end());
                flag = true;
                break;
            }
        }
        if(flag)
            for(long i = 0; i < arr.size(); i++)
                cout << arr[i];
        else
            cout << "-1";
        cout << endl;
    }
	return 0;
}
