//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
void follPatt(string );
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    
	    string s;
	    cin>>s;
	    follPatt(s);
	   
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
void follPatt(string s)
{
    //Your code here
    int res = 1;
    if(s.length() == 1)
        res = 0;
    
    int cnt = 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == 'x')
        {
            if(s[i - 1] == 'y')
            {
                if(cnt != 0)
                {
                    res = 0;
                    break;
                }
                cnt++;
            }
            else
            {
                cnt++;
            }
        }
        else if(s[i] == 'y')
        {
            if(cnt)
                cnt--;
            else
            {
                res = 0;
                break;
            }
        }
    }
    
    if(cnt > 0)
        res = 0;
    
    cout << res; 
   
    cout<<endl;
}