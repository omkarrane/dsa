#include <iostream>
#include<stack>
#include<algorithm> 
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int w = 0; w < t; w++) {
        string s;
        cin >> s;
        stack<int> st;
        long res = 0;
        for(long i = 0; i < s.size(); i++) {
            if(s[i] == '<')
                st.push(1);
            else {
                if(!st.empty())
                    st.pop();
                else
                    break;
                if(st.empty())
                    res = std::max((long)st.size(), i+1);
            }
        }
        cout << res << endl;
    }
	return 0;
}
