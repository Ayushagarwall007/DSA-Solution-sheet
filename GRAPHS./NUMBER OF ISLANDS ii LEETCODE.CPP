// You have a 2D grid of ‘N’ rows and ‘M’ columns which are initially filled with water. You are given ‘Q’ queries each consisting of two integers ‘X’ and ‘Y’ and in each query operation, you have to turn the water at position (‘X’, ‘Y’) into a land. You are supposed to find the number of islands in the grid after each query.

// An island is a group of lands surrounded by water horizontally, vertically, or diagonally.

// Input Format:
// The first line contains an integer ‘T’ denoting the number of test cases. 

// The first input line of each test case contains two single space-separated integers ‘N’ and ‘M’ representing the number of rows and columns of the grid, respectively.

// The second line of each test case contains an integer ‘Q’ representing the number of queries.

// Next ‘Q’ lines contain two single space-separated integers ‘X’ and ‘Y’, representing the coordinates of the grid i.e the coordinates of the point to be turned into land.
// Output Format:
// For each test case, print a single integer denoting the number of islands after each query operation.

// Print the output of each test case in a separate line.
// Note:
// You are not required to print the expected output; it has already been taken care of. Just implement the given function.
// Constraints:
// 1 <= T <= 5
// 1 <= N <= 1000
// 1 <= M <= 1000
// 1 <= Q <= 100000
// 0 <= X < N
// 0 <= Y < M

// Time limit: 1 sec



// #include<vector.h>
class DisjointSet
{
  vector<int>rank,parent,size;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v)return;
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]+=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};    

bool isValid(int adjr,int adjc,int n,int m)
{
    return adjr>=0 and adjr<n and adjc>=0 and adjc<m;
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &operators){
    DisjointSet ds(n*m);
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    int count=0;
    vector<int>ans;
    for(auto it:operators)
    {
        int row=it[0];
        int col=it[1];
        if(vis[row][col]==1)
        {
            ans.push_back(count);
            continue;
        }
        vis[row][col]=1;
        count++;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int ind=0;ind<4;ind++)
        {
            int adjr=row+dr[ind];
            int adjc=col+dc[ind];
            if(isValid(adjr,adjc,n,m))
            {
                if(vis[adjr][adjc]==1)//check if it is already visited or not
                {
                    int nodeNo=row*m+col;
                    int adjnodeNo=adjr*m+adjc;
//                     now checking for its connectivity
                    if(ds.findUPar(nodeNo)!=ds.findUPar(adjnodeNo))
                    {
                        count--;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
            
        }
        ans.push_back(count);
        
    }
    return ans;
    
}


