// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// Alice and Bob have an undirected graph of n nodes and three types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can be traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 105
// 1 <= edges.length <= min(105, 3 * n * (n - 1) / 2)
// edges[i].length == 3
// 1 <= typei <= 3
// 1 <= ui < vi <= n
// All tuples (typei, ui, vi) are distinct.




class Solution {
public:
class dsu{
        public:
        vector<int>parent,sz;
        dsu(int n)
        {
            parent.resize(n);
            sz.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
                sz[i]=1;
            }
        }
        int find_set(int x)
        {
            if(parent[x]==x)return x;
            return parent[x]=find_set(parent[x]);
        }
        bool make_union(int x,int y)
        {
            int a=find_set(x);
            int b=find_set(y);
            if(a==b)return false;
            if(sz[a]<sz[b])swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
            return true;
        }
        int count(int x)
        {
            return sz[x];
        }
};
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>alice,bob,both;
        for(int i=0;i<edges.size();i++)
        {
            int t=edges[i][0];
            int x=edges[i][1]-1;
            int y=edges[i][2]-1;
            if(t==3)
            {
                both.push_back({x,y});
            }
            else if(t==2)
            {
                bob.push_back({x,y});
            }
            else
            {
                alice.push_back({x,y});
            }
        }
        dsu a(n),b(n);
        int ans=0;
        for(auto it:both)
        {
            ans+=a.make_union(it.first,it.second);
            b.make_union(it.first,it.second);
        }
        for(auto it:alice)
        {
             ans+=a.make_union(it.first,it.second);
        }
        for(auto it:bob)
        {
             ans+=b.make_union(it.first,it.second);
        }
        if(a.count(a.find_set(0))<n or b.count(b.find_set(0))<n)return -1;
        return edges.size()-ans;
    }
};








