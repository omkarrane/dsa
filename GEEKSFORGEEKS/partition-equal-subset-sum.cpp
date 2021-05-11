// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int combineSolver(int arr[], int N, int i, long long sum) {
        if (i == N && sum == 0)
            return 1;
        
        if (i == N || sum == 0)
            return 0;
            
        if (dp[i][sum] != -1)
            return dp[i][sum];
            
        int current = 0;
        for (int j = i; j < N; j++) {
            current |= combineSolver(arr, N, j + 1, sum - arr[j]);
            if (current)
                return dp[i][sum] = 1;
        }
        
        return dp[i][sum] = current;
    }
    
    int equalPartition(int N, int arr[])
    {
        // code here
        long long sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
            
        if (sum % 2 == 1)
            return 0;
            
        sum /= 2;
        dp = vector<vector<int>>(N, vector<int>(sum + 1, -1));
        return combineSolver(arr, N, 0, sum);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends