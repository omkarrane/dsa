//Initial Template for C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void sum(vector<pair<int,int>>v);
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<pair<int,int>>v; //Making a vector that holds pairs
	    for(int i=0;i<n;i++)
	    {
	        int x,y;
	        cin>>x>>y;
	        v.push_back(make_pair(x,y)); //Pushing a pair in the vector
	    } 
	    
	   sum(v); //The sum function
	   
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*the function contains vector of pairs*/
//Complete this function to print the sum
void sum(vector<pair<int,int>>v)
{
    long long sum=0;
    for(pair<int, int> p : v)
        sum += p.second;
    cout<<sum;
    cout<<endl;
}