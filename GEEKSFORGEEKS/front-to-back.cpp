//Initial Template for C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void iter(vector<int>::iterator it1,vector<int>::iterator it2);
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        v.push_back(x);
	    }
	    
	    iter(v.begin(),v.end()); //passing begin and end addresses of vector to the function
	   
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
//Complete this function. it1 points to vector.begin(), it2 points to vector.end()
void iter(vector<int>::iterator it1,vector<int>::iterator it2)
{
    vector<int> :: iterator it;
    for(it = it1; it != it2; ++it)
        cout << *it << " ";
    cout<<endl;
}