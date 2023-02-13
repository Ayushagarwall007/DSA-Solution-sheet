// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
// (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
 

// Constraints:

// 1 <= m, n <= 100


// Take eg: arr[5][5], We can come to position(5,5) from (4,5) and (5, 4)
// So if we sum both of them we can get value for (5,5).
// The robot can only move right and down, when we see at some point, it either comes from left or above. 
// If we use dp[i][j] for the present path to arrive at the point (i, j), then the state equation is dp[i][j] = dp[i][j - 1] + dp[i - 1][j].  
// for present value we are using help of previous values.(dynamic programming)
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a 2d vector for m*n and set value to 1; 
		
        vector<vector<int>> dp(m, vector<int>(n, 1));
		
        // Many may confuse by seeing the above line 
        // This is same as dp[m][n] = {0} using array
        
        // iterate to all the grids in m*n and set dp[i][j] = dp[i-1][j] + dp[i][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // Finally result the last grid ans
        return dp[m - 1][n - 1];
        
    }
};







class Solution {
public:
int dp[101][101];
int solve(int i,int j,int m,int n)
{
    if(i>=m || j>=n)return 0;
    if(i==m-1 and j==n-1)return 1;
    if(dp[i][j])return dp[i][j];
    return dp[i][j]=solve(i+1,j,m,n)+solve(i,j+1,m,n);
}
    int uniquePaths(int m, int n) {
        return solve(0,0,m,n);
    }
};
