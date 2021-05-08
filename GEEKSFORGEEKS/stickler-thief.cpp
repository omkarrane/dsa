// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends



class Solution
{
    public:
    ll combineSolver(ll arr[], ll n, ll i, vector<ll> &dp) {
        if (i >= n)
            return 0;
            
        if (dp[i] != -1)
            return dp[i];
            
        return dp[i] = max(combineSolver(arr, n, i + 1, dp), arr[i] + combineSolver(arr, n, i + 2, dp));
    }
    
    //Function to find the maximum money the thief can get.
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code here
        vector<ll> dp(n + 2, -1);
        return combineSolver(arr, n, 0, dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		ll n;
		cin>>n;
		ll a[n];
		
		//inserting money of each house in the array
		for(ll i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends