//Initial Template for C++
#include <iostream>
using namespace std;
// Function prototype
void swapElements(int[], int);
//Position this line where user code will be pasted.
// Driver code to test swapElements
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int sizeof_array;
	    cin >> sizeof_array;
	    
	    int arr[sizeof_array];
	    
	    for(int i = 0;i<sizeof_array;i++){
	        cin >> arr[i];
	    }
        
        // calling function to swap the array swap elements
	    swapElements(arr, sizeof_array);
	    
	    // Printing the modified array
	    for(int i = 0;i<sizeof_array;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to swap array elements
* arr : array input
* sizeof_array : number of elements in array
*/
void swapElements(int arr[], int sizeof_array){
    // Your code here
    for(int i = 0; i < sizeof_array - 2; i++)
    {
        swap(arr[i], arr[i + 2]);
    }
}