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
int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int row,int col,int n,int m)
{
    vis[row][col]=1;
    queue<pair<pair<int,int>,int>>q;
    q.push({{row,col},1});
    int area=1;
    int delrow[]={-1,1,0,0};
    int delcol[]={0,0,-1,1};
    while(!q.empty())
    {
        int r=q.front().first.first;
        int c=q.front().first.second;
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int newr=r+delrow[i];
            int newc=c+delcol[i];
            if(newr>=0 and newc>=0 and newr<n and newc<m and !vis[newr][newc] and grid[newr][newc]==1)
            {
                vis[newr][newc]=1;
                area++;
                q.push({{newr,newc},area});
            }
        }
    }
    return area;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxArea=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=bfs(grid,vis,i,j,n,m);
                    maxArea=max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};
