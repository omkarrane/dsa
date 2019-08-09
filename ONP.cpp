#include <bits/stdc++.h>
using namespace std;

int main() {
        int t;
        cin >> t;
        while(t--) {
                string s;
                stack<string> var, op;
                cin >> s; 
                for(int i = 0; i < s.size(); i++) {
                        if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^') {
                        	string t1(1, s[i]);
                        	op.push(t1);	
                        }
                        else if(s[i] >= 'a' && s[i] <= 'z') {
                        	string t2(1, s[i]);
                        	var.push(t2);	
                        }
                        else if(s[i] == ')') {
                                if(!var.empty() && !op.empty()) {
                                        string temp;
                                        temp = var.top();
                                        var.pop();
                                        temp += op.top();
                                        op.pop();
                                        temp = var.top() + temp;
                                        var.pop();
                                        var.push(temp);
                                }
                        }
                }

                cout << var.top() << endl;
        }
        return 0;
}
