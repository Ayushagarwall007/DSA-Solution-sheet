// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

// Example 1:


// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:


// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// All the elements of graph[i] are unique.
// The input graph is guaranteed to be a DAG.



class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(int src, vector<vector<int>> &graph, vector<int> adj[], int n)
    {
        temp.push_back(src);

        if (src == n - 1)
            ans.push_back(temp);

        for (auto i : adj[src])
            dfs(i, graph, adj, n);

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
                adj[i].push_back(it);
        }

        dfs(0, graph, adj, n);

        return ans;
    }
};
