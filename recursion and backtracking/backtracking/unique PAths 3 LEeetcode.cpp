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





class Solution {
public:

    vector<vector<int>> visited;
    int totalNumberOfWays = 0;

    // Recursive function for traversing all paths
    void findPaths(int row, int col, int stepsRemaining, vector<vector<int>> &grid){
        
        // Checking if the square is valid or not
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size()){
            return;
        }

        // Checking whether the square is available or not
        if(grid[row][col] == -1 || visited[row][col] == 1){
            return;
        }

        // Base Case
        if(grid[row][col] == 2){
            // checking if the path covered all squares or not
            if(stepsRemaining == 0){
                totalNumberOfWays++;
            }
            return;
        }

        // Marking the square as visited
        visited[row][col] = 1;

        // Recursive Calls for all adjacent squares
        findPaths(row - 1, col, stepsRemaining - 1, grid);
        findPaths(row + 1, col, stepsRemaining - 1, grid);
        findPaths(row, col - 1, stepsRemaining - 1, grid);
        findPaths(row, col + 1, stepsRemaining - 1, grid);

        // Unmarking the square
        visited[row][col] = 0;

    }

    int uniquePathsIII(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int x = 0;
        int y = 0;
        int totalSteps = 0;
        visited.resize(m, vector<int>(n, 0));

        // counting total number of available squares
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == -1){
                    continue;
                }
                if(grid[i][j] == 1){
                    x = i;
                    y = j;
                }
                totalSteps++;
            }
        }
        

        findPaths(x, y, totalSteps - 1, grid);

        return totalNumberOfWays;
        
    }
};
