// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

 

// Example 1:


// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:


// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1




// class Solution {
// public:
// int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
//         queue<pair<int,pair<int,int>>>q;
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>dist(n,vector<int>(m,1e9));
//         dist[source.first][source.second]=0;
//         q.push({0,{source.first,source.second}});
//         int dr[]={-1,0,1,0};
//         int dc[]={0,1,1,-1};
//         while(!q.empty());
//         {
//             auto it=q.front();
//             q.pop();
//             int dis=it.first;
//             int r=it.second.first;
//             int c=it.second.second;
//             for(int i=0;i<4;i++)
//             {
//                 int newr=r+dr[i];
//                 int newc=c+dc[i];
//                 if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1 and dis+1<dist[newr][newc]) 
//                 {
//                        dist[newr][newc]=dis+1;
//                        if(newr==destination.first and newc==destination.second)
//                        {
//                            return dis+1; 
//                         }
//                         q.push({1+dis,{newr,newc}});
//                 }
//             }
//         }
//         return -1;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
//     }
// };



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows=grid.size();
        if(rows==0)
            return 0;
        int cols=grid[0].size();
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1)
            return -1;
        vector<vector<int> >visited(rows,vector<int> (cols,INT_MAX));
        queue<vector<int> >q;
        q.push({0,0,1});
        visited[0][0]=1;
        int directions[8][2]={{0,1},{0,-1},{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1}};
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x=v[0]+directions[i][0];
                int y=v[1]+directions[i][1];
                if(x>=0 && x<rows && y>=0 && y<cols && grid[x][y]==0 && visited[x][y]>v[2]+1){
                    visited[x][y]=v[2]+1;
                    q.push({x,y,v[2]+1});
                }
            } 
        }
        return visited[rows-1][cols-1]==INT_MAX ? -1 : visited[rows-1][cols-1];
    }
};





