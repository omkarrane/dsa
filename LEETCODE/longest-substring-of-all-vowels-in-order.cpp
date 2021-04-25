#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 0, curr = 0;
        int a = 0, e = 0, o = 0, i = 0, u = 0;
        if (word[0] == 'a')
            a++;
        
        for (int j = 1; j < word.size(); j++) {
            if (word[j] >= word[j - 1]) {
                if (word[j] == 'a')
                    a++;
                else if (word[j] == 'e')
                    e++;
                else if (word[j] == 'i')
                    i++;
                else if (word[j] == 'o')
                    o++;
                else if (word[j] == 'u')
                    u++;
            }
            else if (word[j] == 'a') {
                a = 1;
                e = 0;
                i = 0;
                o = 0;
                u = 0;
            }
            else {
                a = 0;
                e = 0;
                i = 0;
                o = 0;
                u = 0;
            }
            
            if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0)
                ans = max(ans, a + e + i + o + u);
        }
        
        return ans;
    }
};