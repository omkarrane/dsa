// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    vector<vector<int>> dp;
    
    int combineSolver(int a, int b, int i, int j) {
        if (i == a && j == b)
            return 1;
        
        if (i > a || j > b)
            return 0;
            
        if (dp[i][j] != -1)
            return dp[i][j];
        
        return dp[i][j] = combineSolver(a, b, i + 1, j) + combineSolver(a, b, i, j + 1);
    }
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        // dp = vector<vector<int>>(a, vector<int>(b, -1));
        // return combineSolver(a - 1, b - 1, 0, 0);
        
        vector<vector<int>> dp(a, vector<int>(b));
        dp[0][0] = 1;
        
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (i < a - 1)
                    dp[i + 1][j] += dp[i][j];
                if (j < b - 1)
                    dp[i][j + 1] += dp[i][j];
            }
        }
        
        return dp[a - 1][b - 1];
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends