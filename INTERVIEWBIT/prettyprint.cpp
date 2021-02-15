#include <bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/prettyprint/
vector<vector<int> > prettyPrint(int A) {
    int rowStart = 0, rowEnd = (A * 2) - 2;
    int colStart = 0, colEnd = (A * 2) - 2;
    vector<vector<int>> B((A * 2) - 1, vector<int> ((A * 2) - 1));
    while (colStart <= colEnd && rowStart <= rowEnd && A > 0) {
        int i = colStart;
        while (i <= colEnd)
            B[rowStart][i++] = A;
        rowStart++;
        
        int j = rowStart;
        while (j <= rowEnd)
            B[j++][colEnd] = A;
        colEnd--;
        
        i = colEnd;
        while (i >= colStart)
            B[rowEnd][i--] = A;
        rowEnd--;
        
        j = rowEnd;
        while (j >= rowStart)
            B[j--][colStart] = A;
        colStart++;
        
        A--;
    }
    
    return B;
}
