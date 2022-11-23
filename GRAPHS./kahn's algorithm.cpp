// topological sort using bfs is kahn's algorithm
// indegree is the number of incoming edges in the graph
class Solution
{
  {
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    vector<int>topo;
	    
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        topo.push_back(node);
	       // node is your toposort
	       //so remove it from the indegree
	        for(auto i:adj[node])
	        {
	        indegree[i]--;
	        if(indegree[i]==0)q.push(i);
	        }
	        
	        
	    }
	    return topo;
	}
};
