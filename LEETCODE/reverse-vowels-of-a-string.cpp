#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-vowels-of-a-string/
/**
 * use a 2 pointer approach where i = 0 and j = length of s
 * once both i and j are at vowles, swap them
 * else keep incrementing/decrementing i and j
*/ 
class Solution {
public:
    bool isVowel(char a) {
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' ||
            a == 'I' || a == 'O' || a == 'U';
    }
    
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (isVowel(s[i]) && isVowel(s[j])) {
                char a = s[i];
                s[i] = s[j];
                s[j] = a;
                i++;
                j--;
            }
            else if (!isVowel(s[i])) {
                i++;
            }
            else if (!isVowel(s[j])) {
                j--;
            }
        }
        
        return s;
    }
};