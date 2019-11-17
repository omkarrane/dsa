//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
    Rectangle(){}
    Rectangle(int l,int b)
    {
        length=l;
        breadth=b;
    }
    
};
int area(Rectangle r);
void maxArea(Rectangle arr[],int n);
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;//Number of rectangle objects
	    Rectangle arr[n]; //array of rectangle objects
	    for(int i=0;i<n;i++)
	    {
	        int l,b;
	        cin>>l>>b; //length and breadth of a object
	        Rectangle r(l,b); //creating a object r
	        arr[i]=r; //fill the array
	    }
	    maxArea(arr,n); //function to calculate maxArea
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
int area(Rectangle r)
{
    return r.length*r.breadth;
}
void maxArea(Rectangle arr[],int n)
{
    int max = 0;
    for(int i = 0; i < n; i++) {
        int temp = area(arr[i]);
        if(max < temp)
            max = temp;
    }
    cout << max << endl;
}