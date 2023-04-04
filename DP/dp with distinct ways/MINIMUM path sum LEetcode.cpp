// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 100




// class Solution {
// public:
// int solve(int x,int y,vector<vector<int>>&grid)
// {
//     if(x==0 and y==0)return grid[x][y];
//     int up=10e5,left=10e5;
//     if(x-1>=0)up=grid[x][y]+solve(x-1,y,grid);
//     if(y-1>=0)left=grid[x][y]+solve(x,y-1,grid);
//     return min(up,left);
// }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         return solve(m-1,n-1,grid);
//     }
// };



class Solution {
public:
    int helper(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& memo){
        if(x == 0 and y == 0){
            return grid[x][y];
        }
        if(memo[x][y] != -1) return memo[x][y];
        
        int up = 10e5, left = 10e5;
        if(x-1 >= 0) up = grid[x][y] + helper(x-1, y, grid, memo);
        if(y-1 >= 0) left = grid[x][y] + helper(x, y-1, grid, memo);
        
        return memo[x][y] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(m-1, n-1, grid, memo);
    }
};




// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp (m, vector<int>(n, 0));
//         dp[0][0] = grid[0][0];
//         for(int x=0; x<m; x++){
//             for(int y=0; y<n; y++){
//                 if(x == 0 and y == 0) continue;
//                 int up = 10e5, left = 10e5;
//                 if(x-1 >= 0) up = grid[x][y] + dp[x-1][y];
//                 if(y-1 >= 0) left = grid[x][y] + dp[x][y-1];
                
//                 dp[x][y] = min(up, left);
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };




// // BACKTRACKING SOLUTION
// void funct(int i,int j,int m,int n,vector<vector<int>> grid,vector<int>& ans,int sum){
//         if(i == m or j == n){
//             ans.push_back(sum);
//             return;
//         }
//         if(i == m-1){
//             funct(i,j+1,m,n,grid,ans,sum+grid[i][j]);
//         }
//         else if(j == n-1){
//             funct(i+1,j,m,n,grid,ans,sum+grid[i][j]);
//         }
//         else{
//             funct(i+1,j,m,n,grid,ans,sum+grid[i][j]);
//             funct(i,j+1,m,n,grid,ans,sum+grid[i][j]);
//         }
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         vector<int> ans;
//         int sum=0;
//         int m = grid.size(),n = grid[0].size();
//         funct(0,0,m,n,grid,ans,sum);
//         sort(ans.begin(),ans.end());
//         return ans[0];
// *     }``
