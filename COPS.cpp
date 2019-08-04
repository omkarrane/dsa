#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int w = 0; w < t; w++) {
        int m, x, y;
        cin >> m >> x >> y;
        int arr[m];
        int houses[111];
        memset(houses, 0, sizeof(houses));
        int cops_run = x * y;
        for(int i = 0; i < m; i++)
            cin >> arr[i];
        
        for(int i = 0; i < m; i++) {
            for(int j = arr[i]; (j <= (arr[i]+cops_run)) && j <= 100; j++)
                houses[j] = 1;
            for(int j = arr[i]; (j >= (arr[i]-cops_run)) && j >= 1; j--)
                houses[j] = 1;
        }
        
        int count = 0;
        for(int i = 1; i < 101; i++)
            if(houses[i] == 0)
                count++;
        cout << count << endl;
    }
	return 0;
}
