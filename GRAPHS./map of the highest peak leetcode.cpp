// You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

// If isWater[i][j] == 0, cell (i, j) is a land cell.
// If isWater[i][j] == 1, cell (i, j) is a water cell.
// You must assign each cell a height in a way that follows these rules:

// The height of each cell must be non-negative.
// If the cell is a water cell, its height must be 0.
// Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or
// west of the latter (i.e., their sides are touching).
// Find an assignment of heights such that the maximum height in the matrix is maximized.

// Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

// Example 1:



// Input: isWater = [[0,1],[0,0]]
// Output: [[1,0],[2,1]]
// Explanation: The image shows the assigned heights of each cell.
// The blue cell is the water cell, and the green cells are the land cells.
// Example 2:



// Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
// Output: [[1,1,0],[0,1,1],[1,2,2]]
// Explanation: A height of 2 is the maximum possible height of any assignment.
// Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

// Constraints:

// m == isWater.length
// n == isWater[i].length
// 1 <= m, n <= 1000
// isWater[i][j] is 0 or 1.
// There is at least one water cell.




class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>>ans(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[4]={0,0,0-1,1};
            int dy[4]={-1,1,0,0};
            for(int i=0;i<4;i++)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0 and xx<r and yy>=0 and yy<c and ans[xx][yy]>1+ans[x][y])
                {
                     ans[xx][yy]=1+ans[x][y];
                     q.push({xx,yy});
                }
            }
        }
        return ans;
    }
};



// So Here the simple intuition is that we take a 2d answer matrix and initialize all its values to INT_MAX. Then when we find any water block (isWater[i][j] == 1)
// then i will push those indexes inside the queue and mark the ans[i][j] = 0 as the water block should have height 0. Now my x contains the I index and y will 
// contain the j index values. now we iterate in all 4 directions checking if the position is valid and if ans[xx][yy] (adjacent block) is greater than 1 + ans[x][y]
// (current block) we want absolute height difference to be at most 1 so we check this condition and update the value and pushing the new block index to the queue so 
// that its adjacent elements get filled up. Lastly, we return the ans vector.
