// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

// Note: Topological Sorting for a graph is not possible if the graph is not a DAG.


// We start from a vertex, we first print it, and then 
// Recursively call DFS for its adjacent vertices. 
// In topological sorting,

// We use a temporary stack. 
// We don’t print the vertex immediately, 
// we first recursively call topological sorting for all its adjacent vertices, then push it to a stack. 
// Finally, print the contents of the stack. 
// Note: A vertex is pushed to stack only when all of its adjacent vertices (and their adjacent vertices and so on) are already in the stack

// Approach:

// Create a stack to store the nodes.
// Initialize visited array of size N to keep the record of visited nodes.
// Run a loop from 0 till N
// if the node is not marked True in visited array
// Call the recursive function for topological sort and perform the following steps.
// Mark the current node as True in the visited array.
// Run a loop on all the nodes which has a directed edge to the current node
// if the node is not marked True in the visited array:
// Recursively call the topological sort function on the node
// Push the current node in the stack.
// Print all the elements in the stack.



class Solution
{
   private:
    void dfs(int node,int vis[],stack<int>&st,vector<int> adj[])
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i])
            dfs(i,vis,st,adj);
        }
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
  }
};
