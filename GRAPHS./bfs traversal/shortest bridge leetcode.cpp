// 934. Shortest Bridge
// Medium
// 4.7K
// 180
// Companies
// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

 

// Example 1:

// Input: grid = [[0,1],[1,0]]
// Output: 1
// Example 2:

// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2
// Example 3:

// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 

// Constraints:

// n == grid.length == grid[i].length
// 2 <= n <= 100
// grid[i][j] is either 0 or 1.
// There are exactly two islands in grid.




class Solution {
public:
void dfs(vector<vector<int>>&A,vector<vector<bool>>&vis,queue<pair<int,int>>&q,int i,int j,vector<vector<int>>&dirs)
{
    if(i<0 or j<0 or i>=A.size() or j>=A[0].size() or vis[i][j] or A[i][j]==0)
    {
        return;
    }
    vis[i][j]=1;
    q.push({i,j});
    for(auto &dir:dirs)
    {
        dfs(A,vis,q,i+dir[0],j+dir[1],dirs);
    }
}// this dfs is used to find the first island.....and mark all the 1's of the 1st island as visited
    int shortestBridge(vector<vector<int>>& A) {
        int m=A.size(),n=A[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>>q;
        bool found=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(A[i][j]==1)
                {
                    dfs(A,vis,q,i,j,dirs);
                    found=true;
                    break;
                    
                }
            }
            if(found==true)break;
        }
        int step=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size-->0)
            {
                auto cur=q.front();
                q.pop();
                for(auto &dir:dirs)
                {
                    int i=cur.first+dir[0];
                    int j=cur.second+dir[1];
                    if(i>=0 and j>=0 and i<m and j<n and !vis[i][j])
                    {
                        if(A[i][j]==1)
                        {
                            return step;
                        }
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                    
                }
            }
            step++;
        }
        return -1;
    }
};

// in this question first we have to find the fully island1 with all the elements as 1 and mark them visited and then push all the elements of the island 1 into the queue aab hurr ekkk visited element se 4 directional mai jaayege or jaisee hii kissi bhi element se 1 aayega jo unvisirted hai vaise hi step return kaar denge or break kaar denge.
