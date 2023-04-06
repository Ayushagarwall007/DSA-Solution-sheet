// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

 

// Example 1:



// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).
// Example 2:



// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1
// Example 3:

// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
 

// Constraints:

// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1




class Solution {
private:
    bool isClosed(vector<vector<int>>& grid, int i, int j) {
        // Out of bounds are not considered close
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size())return false;
        
        // Return true if it's water or a visited cell
        if (grid[i][j] == 1 || grid[i][j] == 2) return true;

        // Mark current land as visited
        grid[i][j] = 2;

        // Check if all 4 directions are closed recursively.
        bool isLeftClosed = isClosed(grid, i, j - 1);
        bool isRightClosed = isClosed(grid, i, j + 1);
        bool isTopClosed = isClosed(grid, i + 1, j);
        bool isBottomClosed = isClosed(grid, i - 1, j);

        return isLeftClosed && isRightClosed && isTopClosed && isBottomClosed;
    }

public:
    // T:O(n*m), S:O(n*m)
    int closedIsland(vector<vector<int>>& grid) {
        int islands = 0;

        // Go through all cells in a grid
        for(int i = 0; i < grid.size(); i++) { // O(n)
            for(int j = 0; j < grid[i].size(); j++) { // O(m)
                if(grid[i][j] == 0 && isClosed(grid, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};
