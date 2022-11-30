// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

// Example 1:


// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
// Example 2:


// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]
 

// Constraints:

// 1 <= n <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.




// Approach:

// Find in-degree of all the vertices.
// Vertices with in-degree 1 are the leaf nodes.
// Keep removing leaves level by level until you reach the middle of the graph with maximum 2 vertices.
// There will be maximum 2 such vertices that will form minimum height trees. (middle of the graph)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return{};
        if(n==1) return {0};
        vector<int>adj[n];
        vector<int>indegree(n,0);
        vector<int> ans;
        for(auto vec:edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            indegree[vec[0]]++;
            indegree[vec[1]]++;
        }
        queue<int>q;
       for(int i=0;i<n;i++)
       {
           if(indegree[i]==1)
           q.push(i);
       }

        while(!q.empty())
        {
            int size=q.size();
            ans.clear();
            for(int i=0;i<size;i++)
            {
                int x=q.front();
                q.pop();
                ans.push_back(x);
                
                for(auto i:adj[x])
                {
                    indegree[i]--;
                    if(indegree[i]==1)
                    q.push(i);
                }

            }
        }
        return ans;

    }
};
