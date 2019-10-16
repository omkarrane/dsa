//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
void checkString(string s);
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
	    
	    string s;
	    getline(cin,s);
	    checkString(s);
	   
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
void checkString(string s)
{
    int v=0;
    int c=0;
    
    //Your code here
    for(int i = 0; i < s.length(); i++)
        if(s[i] != ' ')
          if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
              v++;
          else
              c++;
    
    cout << v << " " << c << endl;
    if(v>c)
    cout<<"Yes";
    else if(c>v)
    cout<<"No";
    else
    cout<<"Same";
    
    cout<<endl;
}