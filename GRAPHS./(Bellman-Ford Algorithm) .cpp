// Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: If the Graph contains a negative cycle then return an array consisting of only -1.

// Example 1:

// Input:

// E = [[0,1,9]]
// S = 0
// Output:
// 0 9
// Explanation:
// Shortest distance of all nodes from
// source is printed.
// Example 2:

// Input:

// E = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]]
// S = 2
// Output:
// 1 6 0
// Explanation:
// For nodes 2 to 0, we can follow the path-
// 2-0. This has a distance of 1.
// For nodes 2 to 1, we cam follow the path-
// 2-0-1, which has a distance of 1+5 = 6,
 




// this algorithm us also used to find out the distance of the other nodes from the single source 
// this algo is used to find out the negative cyles in the graph
// it also works on the negative weighted edges also
// .for the n number of edges or nodes we have to relex all the edges n-1 times sequentially ie
// for node u to v with weight wt
// edges can be in any order
// if(dist[u] +wt<dist[v]) dist[v]=dist[u] +wt
// that means after n-1 iterations the distance array will give give all the shortest distance 

// to check for the negative cycle if on the nth iteration if on relaxing the nodes if the distance array is updated then it means the negative cycle is existed in the graph
class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int>dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto it:edges)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                if( dist[u]!=1e8 and dist[u]+wt<dist[v])
                dist[v]=dist[u]+wt;
            }
        }
        // checking for the negative cycles by Nth relexation
        for(auto it:edges)
        {
             int u=it[0];
                int v=it[1];
                int wt=it[2];
                  if( dist[u]!=1e8 and dist[u]+wt<dist[v])
                return {-1};
        }
        return dist;
    }
};
