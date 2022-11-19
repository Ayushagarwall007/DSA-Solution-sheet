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
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    
	    queue<pair<pair<int,int>,int>>q;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==0){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }else vis[i][j]=0;
	        }
	    }
	    
	    int dx[4]={0,0,1,-1};
	    int dy[4]={1,-1,0,0};
	    
	    
	    while(!q.empty()){
	        int i=q.front().first.first;
	        int j=q.front().first.second;
	        int stpes=q.front().second;
	        
	        q.pop();
	        ans[i][j]=stpes;
	        for(int k=0;k<4;k++){
	            int x=i+dx[k];
	            int y=j+dy[k];
	            
	            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0){
	                vis[x][y]=1;
	                q.push({{x,y},stpes+1});
	            }
	        }
	        
	        
	    }
	    return ans;
    }
};
