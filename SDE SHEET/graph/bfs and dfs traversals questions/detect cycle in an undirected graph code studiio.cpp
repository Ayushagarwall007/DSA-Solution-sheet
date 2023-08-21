class Graph {
bool bfs(int src,vector<int>adj[],vector<bool>&vis)
{
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src]=true;

    while(!q.empty())
    {
        int  node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto nbr:adj[node])
        {
            if(!vis[nbr])
            {
                q.push({nbr,node});
                vis[nbr]=true;
            }
            else if(vis[nbr] and nbr!=parent)
            {
                return true;
            }
        }
    }
    return false;
}
public:
    bool detectCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(bfs(i,adj,vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
