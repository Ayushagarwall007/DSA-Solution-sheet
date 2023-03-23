// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example 1:


// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
// Example 2:


// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
// Output: 2
// Example 3:

// Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
// Output: -1
// Explanation: There are not enough cables.
 

// Constraints:

// 1 <= n <= 105
// 1 <= connections.length <= min(n * (n - 1) / 2, 105)
// connections[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// There are no repeated connections.
// No two computers are connected by more than one cable.




class Solution {
public:
void dfs(vector<int>adj[],vector<int>&vis,int i)
{
    vis[i]=1;
    for(auto num:adj[i])
    {
        if(!vis[num])
        dfs(adj,vis,num);
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto a:connections)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);

        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(adj,vis,i);
            }
        }
        int len=connections.size();
        if(len>=n-1)return count-1;
        return -1;
        
    }
};


// USING DSA  UNION APPRACH

class DSU{
    vector<int> rank, parent;
    public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int findParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = findParent(parent[u]);
    }
    
    void unionParent(int u, int v){
        int parU = findParent(u);
        int parV = findParent(v);
        
        if(rank[parU] < rank[parV]){
            parent[parU] = parV;
        }
        else if(rank[parV] < rank[parU]){
            parent[parV] = parU;
        }
        else if(rank[parU] == rank[parV]){
            parent[parU] = parV;
            rank[parV] += 1;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        
        //In order to make graph connected, there should be at least n-1 edges
        if(edges < n-1) return -1;
        
        //Use union find to count number of connected components
        //No. of operations needed = TotalConnectedComp - 1.
        
        int connectedComponent = n;
        DSU ds(n);
        for(auto& edge: connections){
            int u = edge[0], v = edge[1];
            int parU = ds.findParent(u);
            int parV = ds.findParent(v);
            
            if(parU != parV){
                ds.unionParent(u, v);
                connectedComponent -= 1;
            }
        }
		int operationsNeeded = connectedComponent - 1;
        return operationsNeeded;
    }
};
