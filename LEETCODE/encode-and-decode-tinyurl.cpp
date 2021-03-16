#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/encode-and-decode-tinyurl/
class Solution {
public:
    unordered_map<string, string> m1;  // long to short
    unordered_map<string, string> m2;  // short to long
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (m1.find(longUrl) == m1.end()) {
            int r = rand();
            m1[longUrl] = to_string(r);
            m2[to_string(r)] = longUrl;
            return m1[longUrl];
        }
        return m1[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (m2.find(shortUrl) != m2.end())
            return m2[shortUrl];
        return "0";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));