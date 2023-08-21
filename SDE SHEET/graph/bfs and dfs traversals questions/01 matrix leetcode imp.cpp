// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:


// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.



// USING bfs if we take all the ones at the starting point and check for the next zeroes which are at the position of one step and then if we check for the another zeroes at th3e another level then they are at the distance of zeroes

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
				int m=grid[0].size();
				vector<vector<int>>ans(n,vector<int>(m,0));
				queue<pair<pair<int,int>,int>>q;
				vector<vector<int>>vis(n,vector<int>(m,0));
				for(int i=0;i<n;i++)
				{
					for(int j=0;j<m;j++)
					{
						if(grid[i][j]==0)
						{
							vis[i][j]=1;
							q.push({{i,j},0});
						}
						else
						{
							vis[i][j]=0;
						}
					}
				}
			int delr[]={-1,0,1,0};
			int delc[]={0,1,0,-1};
				while(!q.empty())
				{
					int row=q.front().first.first;
					int col=q.front().first.second;
					int steps=q.front().second;
					q.pop();
					ans[row][col]=steps;
					for(int i=0;i<4;i++)
					{
						int newr=delr[i]+row;
						int newc=delc[i]+col;

						if(newr>=0 and newr<n and newc>=0 and newc<m and !vis[newr][newc])
						{
									vis[newr][newc]=1;
									q.push({{newr,newc},steps+1});
						}              
					}

				}
				return ans;
    }
};
