// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

 

// Example 1:


// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Output: false
// Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
// Example 2:


// Input: graph = [[1,3],[0,2],[1,3],[0,2]]
// Output: true
// Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

// Constraints:

// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.



// linear graph with no cycles are bipartite graph
// any graph with the even cycle length is bipartitie
// any graph with the odd cycle length is biparirite

// using bfs approach 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(!visited[i])
            {
                if(checkBipartite(i,visited,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }

bool checkBipartite(int curr,vector<int>& visited,vector<vector<int>>&graph)
{
    int size=graph.size();
    vector<int> color(size,-1);
    vector<int>parent(size,-1);
    visited[curr]=1;
    color[curr]=0;
    queue<int>nodes;
    nodes.push(curr);

    while(!nodes.empty())
    {
        int currNode=nodes.front();
        nodes.pop();
        for(auto nbr:graph[currNode])
        {
            if(!visited[nbr])
            {
                color[nbr]=(color[currNode]==0)?1:0;
                parent[nbr]=currNode;
                visited[nbr]=1;
                nodes.push(nbr);
            }
            else
            {
                if(nbr!=parent[currNode] and color[nbr]==color[currNode]) return false;
            }
        }
    }
    return   true;
}
};






// .USING DFS ALGORITHM TO SOLVE THIS QUESTION

// using dfs solution
// A. Traverse each node of the graph and try to assign a color to them such that alternating nodes are of same color.
// B. If at any step, the child node color matches with the parent node color, then the graph is not bipartite.
// C. If no B found, then the graph is bipartite. So, return true at the end.
// D. Here, the two colors are represented by 0 and 1.
class Solution {
public:
vector<int>vis;
vector<int> col;
bool dfs(int v,int c,vector<vector<int>>&graph)
{
    vis[v]=1;
    col[v]=c;
    for(int child:graph[v])
    {
        if(vis[child]==0)
        {
            if(dfs(child,c^1,graph)==false) return false;
        }
        else
        {
            if(col[v]==col[child])
            return false;
        }
    }
    return  true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n);
        col.resize(n);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 and dfs(i,0,graph)==false)
            {
                return false;
            }
        }
        return true;
    }
};
