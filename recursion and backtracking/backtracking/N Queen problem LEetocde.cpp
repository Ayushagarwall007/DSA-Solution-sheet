// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 

// Constraints:

// 1 <= n <= 9



// here we are moving in threee movements 
// 1 straight movemetn  <-------
// 2 left upper diagonal
// 3 left lower diaginal

class Solution {
public:
    vector<vector<string>> ans;
    int nl;

    bool check(vector<string> &v, int row, int col) {
        /* Check this row on left side */
        for(int i=0; i<col; i++) if(v[row][i] == 'Q') return false;
        /* Check upper diagonal on left side */
        for(int i=row, j=col; i>=0 and j>=0; i--, j--) if(v[i][j] == 'Q') return false;
        /* Check lower diagonal on left side */
        for(int i=row, j=col; j>=0 and i<nl; i++, j--) if(v[i][j] == 'Q') return false;

        return true;
    }

    void solve(vector<string> &v, int col) {
        if(col >= nl) {
            ans.push_back(v);
            return;
        }
        
        for(int i=0; i<nl; i++) {
            if(check(v, i, col)) {
                v[i][col] = 'Q';
                solve(v, col+1);
                v[i][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        nl = n;
        vector<string> v(nl, string(nl, '.'));
        solve(v, 0);
        return ans;
    }
};
