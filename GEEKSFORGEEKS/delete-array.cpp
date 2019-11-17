//Initial Template for C++
#include <iostream>
using namespace std;
int main() {
	
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
        
        // Declaring dynamic 1D array
        int *arr = new int[N];
        
        for(int i = 0;i<N;i++){
            cin >> arr[i];
        }
        
        int sum = 0;
	    for(int i = 0;i<N;i++){
	       sum += arr[i];
	    }
	    
	    //Position this line where user code will be pasted.
	    
	    cout << sum << endl;
	    
	    cout << arr[0] << endl;
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Code to delete the array
// Task is to comment the line which deletes 
// the array such that required output is printed
// delete[] arr; //comment this line so memory doesn't get deallocated
