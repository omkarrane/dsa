#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
vector<vector<int> > generateMatrix(int A) {
    vector<vector<int>> res(A);
    for (int i = 0; i < A; i++) {
        vector<int> temp(A);
        res[i] = temp;
    }
    
    int rowStart = 0, rowEnd = A - 1;
    int colStart = 0, colEnd = A - 1;
    int num = 1;
    while (rowStart <= rowEnd && colStart <= colEnd) {
        int i = colStart;
        while (i <= colEnd)
            res[rowStart][i++] = num++;
        rowStart++;
        if (rowStart > rowEnd)
            break;
            
        int j = rowStart;
        while (j <= rowEnd)
            res[j++][colEnd] = num++;
        colEnd--;
        if (colEnd < colStart)
            break;
        
        i = colEnd;
        while (i >= colStart)
            res[rowEnd][i--] = num++;
        rowEnd--;
        if (rowStart > rowEnd)
            break;
        
        j = rowEnd;
        while (j >= rowStart)
            res[j--][colStart] = num++;
        colStart++;
    }
    
    return res;
}
