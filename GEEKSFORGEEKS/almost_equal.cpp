//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// Function Prototype
int countChars(string, string);
// Driver code to test columnWithMaxZeros function
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    
	    // taking string input
	    string s1, s2;
	    cin >> s1 >> s2;
	    
	    cout << countChars(s1, s2) << endl;
	}
	
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*Function to count number of characters 
* to make s1 and s2 equal
* s1 : first string
* s2 : second string
*/
int countChars(string s1, string s2){
    // Your code here
    int cnt1[200] = {0}, cnt2[200] = {0};
    for(int i = 0; i < s1.length(); i++)
        cnt1[s1[i]]++;
        
    for(int i = 0; i < s2.length(); i++)
        cnt2[s2[i]]++;
        
    int res = 0;
    for(int i = 0; i < 200; i++)
        res += abs(cnt1[i] - cnt2[i]);
        
    return res;
}