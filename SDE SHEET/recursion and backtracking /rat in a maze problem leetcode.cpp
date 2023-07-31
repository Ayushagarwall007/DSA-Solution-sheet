// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.
// Example 2:
// Input:
// N = 2
// m[][] = {{1, 0},
//          {1, 0}}
// Output:
// -1
// Explanation:
// No path exists and destination cell is 
// blocked.
// Your Task:  
// You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
// Note: In case of no path, return an empty list. The driver will output "-1" automatically.

// Expected Time Complexity: O((3N^2)).
// Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

// Constraints:
// 2 ≤ N ≤ 5
// 0 ≤ m[i][j] ≤ 1




class Solution{
    public:
    void solve(int i,int j , vector<string>&ans,vector<vector<int>>&vis,string&path,int *di,int *dj,vector<vector<int>>&m , int n)
    {
        if(i==n-1 and j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        string dir="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nextI=i+di[ind];
            int nextJ=j+dj[ind];
             // now checking for every condition that should be in boundry has path==1  and vis is not marked 1
            if(nextI>=0 and nextJ>=0  and nextI<n and nextJ<n and vis[nextI][nextJ]!=1 and m[nextI][nextJ]==1)
            {
                vis[i][j]=1;
                path.push_back(dir[ind]);
                solve(nextI,nextJ, ans , vis , path , di , dj , m ,n);
                vis[i][j]=0;
                path.pop_back();
            }
        }
        
       
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        string path="";
        int di[] = {1,0,0,-1};
        int dj[]={0,-1,+1,0};
        if(m[0][0]==1)solve(0,0,ans,vis,path,di,dj,m,n);
        return ans;
    }
};
