//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// Function Prototype
int countSpecials(int[], int, int);
//Position this line where user code will be pasted.
// Driver code to rest countSpecials function
int main() {
	
	// Testcase input
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    
	    // sizeof_array : number of array elements
	    // K : as given in statement
	    int sizeof_array, K;
	    cin >> sizeof_array >> K;
	    
	    // array of size sizeof_array
	    int arr[sizeof_array];
	    
	    for(int i = 0;i<sizeof_array;i++){
	        cin >> arr[i];
	    }
	    
	    // calling function and printing count the occurrence
	    cout << countSpecials(arr, sizeof_array, K) << endl;
	    
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to count number of elements with occurrence
* exactly equal to floor(sizeof_array/K)
* arr : input array
* sizeof_array : number of array elements
*/
int countSpecials(int arr[], int sizeof_array, int K){
    int f = floor(sizeof_array/K), count = 0;
    int count_arr[1001] = {0};

    // Your code here
    for(int i = 0; i < sizeof_array; i++)
        count_arr[arr[i]]++;
        
    for(int i = 0; i < 1001; i++)
        if(count_arr[i] == f)
            count++;
    
    return count;
}