// Given a boolean 2D matrix. The task is to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms
// an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

// Examples:

// Input: grid[][] = 
// {{1, 1, 0, 0, 0}, 
// 1, 1, 0, 0, 0}, 
// 0, 0, 0, 1, 1}, 
// 0, 0, 0, 1, 1}}
// Output: 1 
// Island 1, 1 at the top left corner is same as island 1, 1 at the bottom right corner
// Input: grid[][] = 
// {{1, 1, 0, 1, 1}, 
// 1, 0, 0, 0, 0}, 
// 0, 0, 0, 0, 1}, 
// 1, 1, 0, 1, 1}}
// Output: 3 
// Distinct islands in the example above are 1, 1 at the top left corner; 1, 1 at the top right corner and 1 at the bottom right corner. 
// We ignore the island 1, 1 at the bottom left corner since 1, 1 it is identical to the top right corner.







#include<bits/stdc++.h>
void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i , int j ,vector<pair<int,int>>&vec,int basei,int basej)  
{
    vis[i][j]=1;
    vec.push_back({i-basei,j-basej});
    int n=grid.size();
    int m=grid[0].size();
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,-1,0,+1};
    for(int k=0;k<4;k++)
    {
        int nrow=i+delrow[k];
        int ncol=j+delcol[k];
        if(nrow>=0 && nrow<n and ncol<m and ncol>=0 and !vis[nrow][ncol] and grid[nrow][ncol]==1 )
        dfs(grid,vis,nrow,ncol,vec,basei,basej);
    }
    
}              

int distinctIslands(int **arr, int n, int m) {
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            grid[i][j]=arr[i][j];
        }
    }
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vector<pair<int,int>>vec;
            if(!vis[i][j] and grid[i][j]==1)
            {
                dfs(grid,vis,i,j,vec,i,j);
                st.insert(vec);
            }
            
        }
        
        
    }
    return st.size();
}
