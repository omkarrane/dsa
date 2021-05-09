// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

struct compare {
    bool operator() (val &p1, val &p2) {
        return p1.second < p2.second;
    }
};

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    //Your code here
    sort(p, p + n, compare());
    vector<int> dp(n);
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (p[j].second < p[i].first)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        
        ans = max(ans, dp[i]);
    }
    
    return ans;
}