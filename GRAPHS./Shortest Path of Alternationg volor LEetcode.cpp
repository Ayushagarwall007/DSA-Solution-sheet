// You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

// You are given two arrays redEdges and blueEdges where:

// redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
// blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
// Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

 

// Example 1:

// Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
// Output: [0,1,-1]
// Example 2:

// Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
// Output: [0,1,-1]
 

// Constraints:

// 1 <= n <= 100
// 0 <= redEdges.length, blueEdges.length <= 400
// redEdges[i].length == blueEdges[j].length == 2
// 0 <= ai, bi, uj, vj < n




// Start from 0 and keep note of color of 0(parent) say it's color as 'prev_color', now go to all it's children and say it's color to 'color'. now check if you came at this node with color not equal to 'prev_color' for first time then note distance as dist[cur_node] = dist[node] + 1. and go ahead.
// Same as above go ahead, but sometime you will get parallel edges so you can go with that edge doesn't matter you have visited that node before OR not, but visit this time through different edge then before
// EXAMPLE : If you visited 1 -> 2 with red edge before now somehow you have edge from 1 -> 2 another time but with blue edge then you can go with that path, remember you are visiting this node 2nd time but it's ok.
// Now, like this go ahead and whenever you go through either new edge OR new node then it's distance will be 1e9(dist[node] = 1e9) as it set earlier, then you will update the shorter distance.
// At the end you will take the minimum distance of a node from either a blue edge OR red edge, If minimum distance if 1e9 it means the shortest path was not possible from 0, means say dist[node] = -1.
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it : redEdges)
        {
            adj[it[0]].push_back({it[1], 1});
        }
        for(auto it : blueEdges)
        {
            adj[it[0]].push_back({it[1], 2});
        }

        vector<vector<int>> dist(n, vector<int> (3, 1e9));

        queue<pair<int, int>> q;

        q.push({0, 0});

        dist[0][0] = 0;

        while(!q.empty())
        {
            int node = q.front().first;
            int prev_color = q.front().second;
            q.pop();

            for(auto it : adj[node])
            {
                int adj_node = it.first;
                int color = it.second;
                if(color == prev_color) continue;
                if(dist[adj_node][color] == 1e9)
                {
                    dist[adj_node][color] = dist[node][prev_color] + 1;
                    q.push({adj_node, color});
                }
            }
        } 

        vector<int> ans(n, 0);

        for(int i = 1; i < n; i++)
        {
            ans[i] = min(dist[i][1], dist[i][2]);
            if(ans[i] == 1e9) 
            {
                ans[i] = -1;
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
//         vector<pair<int, int>> adj[n];
//         for(auto it : redEdges)
//         {
//             adj[it[0]].push_back({it[1], 1});
//         }
//         for(auto it : blueEdges)
//         {
//             adj[it[0]].push_back({it[1], 2});
//         }

//         vector<int> dist(n, -1);
//         vector<vector<bool>> vis(n, vector<bool> (3, false));

//         queue<vector<int>> q;

//         q.push({0, 0, 0}); // {node, steps, color}

//         dist[0] = 0;
//         vis[0][1] = vis[0][2] = true;

//         while(!q.empty())
//         {
//             int node = q.front()[0];
//             int steps = q.front()[1];
//             int prev_color = q.front()[2];
//             q.pop();

//             for(auto it : adj[node])
//             {
//                 int adj_node = it.first;
//                 int color = it.second;
//                 if(color == prev_color) continue;
//                 if(!vis[adj_node][color])
//                 {
//                     vis[adj_node][color] = true;
//                     if(dist[adj_node] == -1) 
//                     {
//                         dist[adj_node] = 1 + steps;
//                     }
//                     q.push({adj_node, 1 + steps, color});
//                 }
//             }
//         } 

//         return dist;
//     }
// };
