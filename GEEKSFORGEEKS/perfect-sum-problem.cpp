// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long mod = 1e9 + 7;
	vector<vector<int>> dp;
	
	long long combineSolver(int arr[], int n, int sum, int index) {
	    if (index == n) {
	        if (sum == 0)
	            return 1;
	        return 0;
	    }
	    
	    if (sum < 0)
	        return 0;
	    
	    if (sum == 0)
	        return 1;
	        
	    if (dp[sum][index] != -1)
	        return dp[sum][index];
	        
	    long long current = 0;
	    current += combineSolver(arr, n, sum - arr[index], index + 1);
	    current %= mod;
	    current += combineSolver(arr, n, sum, index + 1);
	    current %= mod;
	    
	    return dp[sum][index] = current;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        dp = vector<vector<int>>(sum + 1, vector<int>(n, -1));
        return combineSolver(arr, n, sum, 0);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends