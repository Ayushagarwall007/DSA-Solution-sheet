// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4
// Example 2:


// Input: matrix = [["0","1"],["1","0"]]
// Output: 1
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.





class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz;
    }
};



// class Solution {
// public:
//     int solve(vector<vector<char>>&matrix,int i,int j,int &maxi)
//     {
//         if(i>=matrix.size() or j>=matrix[0].size())
//         return 0;
//         int bottom=solve(matrix,i+1,j,maxi);
//         int digonal=solve(matrix,i+1,j+1,maxi);
//         int right=solve(matrix,i,j+1,maxi);
//         if(matrix[i][j]=='1')
//         {
//             int side=min(bottom,min(digonal,right))+1;
//             maxi=max(maxi,side);
//             return side;
//         }
//         else 
//         return 0;

//     }
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int maxi=0;
        
//         solve(matrix,0,0,maxi);
//         return maxi*maxi;
//     }
// };
