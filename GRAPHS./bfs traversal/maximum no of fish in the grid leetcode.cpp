// You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

// A land cell if grid[r][c] = 0, or
// A water cell containing grid[r][c] fish, if grid[r][c] > 0.
// A fisher can start at any water cell (r, c) and can do the following operations any number of times:

// Catch all the fish at cell (r, c), or
// Move to any adjacent water cell.
// Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

// An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

// Example 1:


// Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
// Output: 7
// Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
// Example 2:


// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
// Output: 1
// Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// 0 <= grid[i][j] <= 10



class Solution {
public:
    int ans=0;
    vector<int>dir={0,1,0,-1,0};
    bool isValid(int i ,int j , int  n , int m)
    {
        return (i>=0 and i<n and j>=0 and j<m);
    }
    void solve(int i ,int j,int n,int m,vector<vector<int>>&grid)
    {
        int count=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(isValid(x,y,n,m ) and grid[x][y]!=0)
            {
                count+=grid[x][y];
                grid[x][y]=0;
                for(int tp=1;tp<5;tp++)
                {
                    int nx=x+dir[tp-1];
                    int ny=y+dir[tp];
                    q.push({nx,ny});
                }
            }
        }
        ans=max(count,ans);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    solve(i,j,n,m,grid);
                }
            }
        }
        return ans;
    }
};
