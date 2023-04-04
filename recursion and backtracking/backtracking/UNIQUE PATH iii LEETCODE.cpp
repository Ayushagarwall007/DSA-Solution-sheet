// You are given an m x n integer array grid where grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:


// Input: grid = [[0,1],[2,0]]
// Output: 0
// Explanation: There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// 1 <= m * n <= 20
// -1 <= grid[i][j] <= 2
// There is exactly one starting cell and one ending cell.
// Accepted
// 173.3K
// Submissions
// 212.1K





class Solution {
public:
    void solve(vector<vector<int>> &grid, int r, int c, int &ans,int &NoOfZeroes){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()){
            return;
        }
        if(grid[r][c] == 2){
           if(NoOfZeroes == 0)      // i.e all empty squares are visited
                ans++;
            return;
        }
        if(grid[r][c] == -1) return;
        NoOfZeroes--;
        // for down
        grid[r][c] = -1;
        solve(grid,r+1,c,ans,NoOfZeroes);
        //for right
        solve(grid,r,c+1,ans,NoOfZeroes);
        // for up
        solve(grid,r-1,c,ans,NoOfZeroes);
        // for left
        solve(grid,r,c-1,ans,NoOfZeroes);
        grid[r][c] = 0;
        NoOfZeroes++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0,NoOfZeroes = 1;     // we have to including ending square too it is also empty
        int r,c;
        for(int i =0;i<grid.size();i++){        // searching for starting square
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    r=i;
                    c=j;
                }
                else if(grid[i][j] == 0) 
                    NoOfZeroes ++;
            }
        }
        solve(grid,r,c,ans,NoOfZeroes);
        return ans;
    }
};
