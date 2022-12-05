// kruskal;s algorithm
// firsst sort all the nodes according to their weights
// using the disjoint set concept check if the nodes coming next is not in the same component then add them into theiis
// component if they are already in the same component then don't take it 
 class disjoint_Set
{
    vector<int>rank,parent,size;
    public:
    disjoint_Set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    int findUltimateParent(int node)
    {
        if(node==parent[node])return node;
        return parent[node]=findUltimateParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ultiParU=findUltimateParent(u);
        int ultiParV=findUltimateParent(v);
        if(ultiParU==ultiParV)return;//this means that they belongs to the same component as theyu have the same ultimate parents
        if(rank[ultiParU]<rank[ultiParV])
        parent[ultiParU]=ultiParV;
        
        else if(rank[ultiParV]<rank[ultiParU])
        parent[ultiParV]=ultiParU;
        
        else {
        parent[ultiParU]=ultiParV;//or we can also do parent[ultiParV]=ultiParU;
        rank[ultiParV]++;
        }        
    }
    
    void unionBysize(int u,int v)
    {
        int ultiParU=findUltimateParent(u);
        int ultiParV=findUltimateParent(v);
        if(ultiParU==ultiParV)return;
        if(size[ultiParV]<size[ultiParU])
        {
            parent[ultiParV]=ultiParU;
            size[ultiParU]+=size[ultiParV];
        }
        else
        {
            parent[ultiParU]=ultiParV;
            size[ultiParV]+=size[ultiParU];
        }
        
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                
                edges.push_back({wt,{node,adjNode}});
            }
        }
        disjoint_Set ds(V);
        sort(edges.begin(),edges.end());
        int mstWt=0;
        for(auto it:edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findUltimateParent(u)!=ds.findUltimateParent(v))
            
            {
                mstWt+=wt;
                ds.unionBysize(u,v);
            }
        }
        return mstWt;
    }
