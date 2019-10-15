//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
// Function prototype
int countSumSubsets(int[], int);
//Position this line where user code will be pasted.
// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    int arr[N];
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	            cin >> arr[i];
	        }
	    
	    cout << countSumSubsets(arr, N) << endl;
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to count subset with even sum
* arr : array input
* N : size of array
*/
int countSumSubsets(int arr[], int N){
    // Your code here
    int pow_size = pow(2, N);
    int cnt = 0;
    for(int i = 1; i < pow_size; i++)
    {
        int temp = 0;
        for(int j = 0; j < N; j++)
        {
            if(i & (1 << j))
            {
                temp += arr[j];
            }
        }
        if(temp > 0 && temp % 2 == 0)
            cnt++;
    }
    
    return cnt;
}