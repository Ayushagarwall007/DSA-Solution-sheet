// 1466. Reorder Routes to Make All Paths Lead to the City Zero
// Medium
// 2.5K
// 67
// Companies
// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

 

// Example 1:


// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 2:


// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
// Example 3:

// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
 

// Constraints:

// 2 <= n <= 5 * 104
// connections.length == n - 1
// connections[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi










// Intuition
// We need find the number of road to rearrange in other words number of roads to reverse to reach 0 from each and every node.

// Approach
// We are going to use concept of incoming and out-going edges in node.

// Let's start solving this problem along with code and explanaion of logic behiend each step.....

// first we are going to find adjency list without making changes and one with reverse all the direction of edges. logic behind doing this ... if i could visite some cities/nodes from "A" (Node 0) given city/node that means we can't visit "A" (Node 0) from all visited cities and we need to reverse the direction of each road/edges to visit "A" (node 0).

// for(auto a : con){
//   adj[a[0]].push_back(a[1]); // this is correce adjency list
//   bk[a[1]].push_back(a[0]); // this is reverse adjencct list
// }
// We need a visited array that is for record of visted city/node

// vector<int> vis(n,0);
// Now start traversing by DFS/BFS and find number of cities/node you can visit from node 0 (these are the node which are not coming to node 0) these will be part of our answer.

// queue<int> q;
//         q.push(0);
//         while(!q.empty()){
//             int a = q.front();
//             vis[a] =1;
//             q.pop();
//             for( int no : adj[a]){
//                 if(!vis[no]){
//                     ans++;
//                     q.push(no);
//                 }
//             }
//             for( int no : bk[a]){
//                 if(!vis[no]){
//                     q.push(no);
//                 }
//             }
//         }
// below part of code is to visit all outgoing rodes that will be part of our answer

// for( int no : adj[a]){
//   if(!vis[no]){
//     ans++;
//     q.push(no);
//   }
// }
// this part of code to visit all the incoming roads . city/nodes that are incoming and marking them visited so that not to reapetaion of visiting...

// for( int no : bk[a]){
//   if(!vis[no]){
//     q.push(no);
//   }
// }
// ==========================================================


==========================================================

// Complexity
// Time complexity:
// Space complexity:
// Code
  
  
  
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n) , bk(n);
        vector<int> vis(n,0);
        vis[0] =1;
        for(auto a : con){
            adj[a[0]].push_back(a[1]);
            bk[a[1]].push_back(a[0]);
        }
        int ans=0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int a = q.front();
            vis[a] =1;
            q.pop();
            for( int no : adj[a]){
                if(!vis[no]){
                    ans++;
                    q.push(no);
                }
            }
            for( int no : bk[a]){
                if(!vis[no]){
                    q.push(no);
                }
            }
        }
        return ans;
    }
};
