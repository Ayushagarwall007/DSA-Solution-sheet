// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


// Example 1:

// Input:



// Output: 1
// Explanation: 3 -> 3 is a cycle

// Example 2:

// Input:


// Output: 0
// Explanation: no cycle in the graph

// Your task:
// You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)


// Constraints:
// 1 ≤ V, E ≤ 105




// isme phle humm hurr dfs ki vistied path banayenge or check karenge ki agar koi dusre dfs ki
// path mai voi already visted or same path kaa node incluse hota hai iska matlaabcycle hai nahi 
// too nahi hai
class Solution {
    private:
    bool dfscheck(int node,vector<int>adj[],int vis[],int pathVis[])
    {
        vis[node]=1;
        pathVis[node]=1;
        // traverse for the adjacent nodes
        for(auto i:adj[node])
        {
            if(!vis[i])
            if(dfscheck(i,adj,vis,pathVis)==true) return true;
            else if(pathVis[i])//if the node is previously visited but it has to be visited on the same path
            return true;
    }
    pathVis[node]=0;
    return false;
        }
        
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfscheck(i,adj,vis,pathVis))return true;
            }
        }
        return false;
    }
};


// APPROACH II
// JUST DO THE TOPOLOGICAl sort if the topovector is equal to the size of the adjancy list then it does not contain cycle else it contains cycle 
// so using the topological sort here using the bfs algorithm
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	 bool is Cyclic(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
         int count=0;
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        count++;
	       // node is your toposort
	       //so remove it from the indegree
	        for(auto i:adj[node])
	        {
	        indegree[i]--;
	        if(indegree[i]==0)q.push(i);
	        }
	        
	        
	    }
         if(count==V)return false;
	    return true;
        
        
	}
    
};
