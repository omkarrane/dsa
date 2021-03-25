#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
/**
 * use a stack<char> to store the string. once a closing bracket is encountered, reverse the elements in stack till the first opening bracket
 */
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                stack<char> aux;
                while (st1.top() != '(') {
                    aux.push(st1.top());
                    st1.pop();
                }
                
                st1.pop();
                stack<char> st2;
                while (!aux.empty()) {
                    st2.push(aux.top());
                    aux.pop();
                }
                
                while (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else {
                st1.push(s[i]);
            }
        }
        
        string ans;
        while (!st1.empty()) {
            ans.push_back(st1.top());
            st1.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};