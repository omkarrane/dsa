//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
int M[100][100];
// Function prototype
int columnWithMaxZeros(int);
//Position this line where user code will be pasted.
// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            cin >> M[i][j];
	        }
	    }
	    
	    cout << columnWithMaxZeros(N) << endl;
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to count zeros in each column
* N : Number of rows and columns in array
M is the matrix that is globally declared
*/
int columnWithMaxZeros(int N){
    // Your code here
    int min = INT_MAX, index;
    for(int i = 0; i < N; i++)
    {
        int curr_total = 0;
        for(int j = 0; j < N; j++)
            curr_total += M[j][i];
        
        if(curr_total < min)
        {
            min = curr_total;
            index = i;
        }
    }
    
    return index;   
}