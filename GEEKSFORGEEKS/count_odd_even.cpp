//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// Function Prototype
void countOddEven(int[], int);
//Position this line where user code will be pasted.
// Driver code to test countOddEven function
int main() {
	
	// Testcase input
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int sizeof_array;
	    cin >> sizeof_array;
	    
	    int arr[sizeof_array];
	    
	    // Array elements input
	    for(int i = 0; i < sizeof_array; i++){
	        cin >> arr[i];
	    }
	    
	    // Calling function to count even and odd
	    countOddEven(arr, sizeof_array);
	    
	}
	
	return 0;
}

void countOddEven(int arr[], int sizeof_array)
{
    // your code here
    int even_cnt = 0, odd_cnt = 0;
    for(int i = 0; i < sizeof_array; i++)
    {
        if(arr[i] & 1)
            odd_cnt++;
        else
            even_cnt++;
    }
    cout << odd_cnt << " " << even_cnt << endl;
}