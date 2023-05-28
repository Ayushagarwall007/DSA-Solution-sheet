// You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

// Return the number of complete connected components of the graph.

// A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

// A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

// Example 1:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
// Output: 3
// Explanation: From the picture above, one can see that all of the components of this graph are complete.
// Example 2:



// Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
// Output: 1
// Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

// Constraints:

// 1 <= n <= 50
// 0 <= edges.length <= n * (n - 1) / 2
// edges[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated edges.


class DisjointSet
{
    public:
    vector<int>rank,parent,size,edges;
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        size.resize(n+1,1);
        edges.resize(n+1,0);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find(int node)
    {
        if(node==parent[node])return node;
        else return parent[node]=find(parent[node]);
    }
    // void unionByRank(int u,int v)
    // {
    //     int ulp_u=find(u);
    //     int ulp_v=find(v);
    //     if(ulp_u==ulp_v)return;
    //     if(rank[ulp_u]<rank[ulp_v])
    //     {
    //         parent[ulp_u]=ulp_v;
    //     }
    //     else if (rank[ulp_v]<rank[ulp_u])
    //     {
    //         parent[ulp_v]=ulp_u;
    //     }
    //     else
    //     {
    //         parent[ulp_u]=ulp_v;
    //         rank[ulp_v]++;
    //     }
    // }

    void unionBySize(int u ,int v)
    {
        int ulp_u=find(u);
        int ulp_v=find(v);
        if(ulp_v==ulp_u)
        {
            edges[ulp_u]++;
            return;
        }
       if(size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            edges[ulp_u] += edges[ulp_v]+1;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            edges[ulp_v] += edges[ulp_u]+1;
        }
    }

};
class Solution {
public:

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it:edges)
        {
            ds.unionBySize(it[0],it[1]);
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            int noOfEdges=(ds.size[i]*(ds.size[i]-1))/2;
            if(ds.find(i)==i and ds.edges[i]==noOfEdges)ans++;

        }
        return ans;
    }
};
