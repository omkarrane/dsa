#include <bits/stdc++.h>
using namespace std;

int get_weight(char c) {
        if(c == 'C') return 12;
        else if(c == 'H') return 1;
        else if(c == 'O') return 16;
}

int main() {
        string s;
        cin >> s;
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
                if(s[i] == 'C' || s[i] == 'H' || s[i] == 'O') 
                        st.push(get_weight(s[i]));
                else if(s[i] == '(')
                        st.push(0);
                else if(s[i] == ')') {
                        int sum = 0;
                        while(st.top() != 0) {
                            sum += st.top();
                            st.pop();
                        }
                        st.pop();
                        st.push(sum);
                }
                else {
                        int t = (int)s[i] - 48;
                        while(t > 1) {
                                st.push(st.top());
                                t--;
                        }
                }
        }

        int res = 0;
        while(!st.empty()) {
                res += st.top();
                st.pop();
        }

        cout << res;
        return 0;
}
