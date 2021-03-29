#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/alphabet-board-path/
/**
 * make a map for storing indexes of characters
 * for every character determine the difference between that character and the last position of our pointer
 * handle cases for positive and negative values to move up or down or left or right
 * also handle the case to reach 'z'
*/
class Solution {
public:
    string alphabetBoardPath(string target) {
        unordered_map<char, pair<int, int>> m1;
        vector<string> board = {"abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                m1[board[i][j]] = {i, j};
            }
        }

        string ans;
        int curr1 = 0, curr2 = 0;
        for (int i = 0; i < target.size(); i++) {
            pair<int, int> t1 = m1[target[i]];
            int r = curr1 - t1.first;
            int c = curr2 - t1.second;

            char a = 'U', b = 'L';
            if (r < 0)
                a = 'D';
            if (c < 0)
                b = 'R';

            string s1(abs(r), a), s2(abs(c), b);
            if (t1.first == 5) {
                if ((abs(r)) > 0) {
                    string s3((abs(r) - 1), a);
                    ans.append(s3);
                    ans.append(s2);
                    ans.push_back(a);    
                }
                ans.push_back('!');
            }
            else {
                ans.append(s1);
                ans.append(s2);
                ans.push_back('!');
            }
            curr1 = t1.first;
            curr2 = t1.second;
        }

        return ans;
    }
};