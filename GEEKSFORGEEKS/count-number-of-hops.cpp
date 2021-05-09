// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    vector<long long> dp;
    long long mod = 1e9 + 7;
    vector<int> steps = {1,2,3};
    
    long long combineSolver(int n, int i) {
        if (i == n)
            return 1;
            
        if (i > n)
            return 0;
            
        if (dp[i] != -1)
            return dp[i];
        
        
        long long current = 0ll;
        for (int j = 0; j < 3; j++) {
            current += combineSolver(n, i + steps[j]);
            current %= mod;
        }
        
        return dp[i] = current;
    }
    
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        // dp = vector<long long>(n + 1, -1);
        dp = vector<long long>(n + 1);
        // return combineSolver(n, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < steps.size(); j++) {
                if (i >= steps[j])
                    dp[i] += dp[i - steps[j]];
                dp[i] %= mod;
            }
        }
        
        return dp[n];
    }
};


// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}
  // } Driver Code Ends