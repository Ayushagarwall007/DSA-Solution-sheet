// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// Return the length of the shortest cycle in the graph. If no cycle exists, return -1.

// A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

 

// Example 1:


// Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
// Output: 3
// Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 
// Example 2:


// Input: n = 4, edges = [[0,1],[0,2]]
// Output: -1
// Explanation: There are no cycles in this graph.
 

// Constraints:

// 2 <= n <= 1000
// 1 <= edges.length <= 1000
// edges[i].length == 2
// 0 <= ui, vi < n
// ui != vi
// There are no repeated edges.
// Accepted
// 9K
// Submissions
// 23.3K



class Solution {
public:
    
    int help(int n,vector<int> adj[]){
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            vector<int> dist(n,(1e9));
            vector<int> par(n, -1);
            dist[i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int c : adj[x]) {
                    if (dist[c] == (int)(1e9)) {
                        dist[c] = 1 + dist[x];
                        par[c] = x;
                        q.push(c);
                }
                else if (par[x] != c && par[c] != x)
                    ans = min(ans, dist[x] + dist[c] + 1);
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto i : edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return help(n,adj);
    }
};
