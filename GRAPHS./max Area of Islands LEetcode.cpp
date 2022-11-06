// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.



class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int maxArea = 0, m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j]){
                    int area = 0;
                    DFS(grid, i, j, m, n, area, maxArea);
                }
        return maxArea;
    }
    
    void DFS(vector<vector<int>>& grid, int r, int c, int m, int n, int& area, int& maxArea){
        if(r < 0 || c < 0 || r == m || c == n || grid[r][c] == 0){
            maxArea = max(maxArea, area);
            return;
        }
        area++;
        grid[r][c] = 0;
        DFS(grid, r + 1, c, m, n, area, maxArea);
        DFS(grid, r - 1, c, m, n, area, maxArea);
        DFS(grid, r, c + 1, m, n, area, maxArea);
        DFS(grid, r, c - 1, m, n, area, maxArea);
    }
};
