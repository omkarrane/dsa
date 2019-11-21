#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int arr[], int k, int n)
{
    int set[101] = {0};
    for(int i = 0; i < n; i++)
    {
      set[arr[i]]++;
      if((i+1) >= k)
      {
        int count = 0;
        for(int j = 0; j < 101; j++)
        {
          if(set[j] > 0)
            count++;
        }
        printf("%d ", count);
        set[arr[i-k+1]]--;
      }
    }
}