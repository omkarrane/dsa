#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-sudoku/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<int>> row;
        map<int, set<int>> col;
        map<int, set<int>> box;
        
        for (int i = 0; i < 9; i++) {
            row[i] = set<int>();
            col[i] = set<int>();
            box[i] = set<int>();
        }
        
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                
                int k = board[i][j] - '0';
                int r = i / 3 * 3;
                int c = j / 3 * 3;
                int l = r * 3 + c;
                if (row[i].find(k) != row[i].end() || col[j].find(k) != col[j].end() || box[l].find(k) != box[l].end())
                    return false;
                
                row[i].insert(k);
                col[j].insert(k);
                box[l].insert(k);
            }
        }
        
        return true;
    }
};