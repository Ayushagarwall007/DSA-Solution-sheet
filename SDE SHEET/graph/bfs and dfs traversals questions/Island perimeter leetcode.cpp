// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

// Example 1:


// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4
 

// Constraints:

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] is 0 or 1.
// There is exactly one island in grid.






class Solution
{
public:
    int ans = 0;
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;

        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = r + delrow[i];
            int nc = c + delcol[i];

            if ((nr < 0 or nr == n) and nc >= 0)
                ans++;
                
            if ((nc < 0 or nc == m) and nr >= 0)
                ans++;

            if (nr >= 0 and nr < n and nc >= 0 and nc < m)
            {
                if (!grid[nr][nc])
                    ans++;

                if (grid[nr][nc] and !vis[nr][nc])
                    dfs(nr, nc, grid, vis);
            }
        }
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] and !vis[i][j])
                    dfs(i, j, grid, vis);
            }
        }

        return ans;
    }
};
