



#include<bits/stdc++.h>
void bfs(int v,vector<int>&vis,vector<vector<int>>&adj,vector<int>&indegree,vector<int>&ans)
{
  queue<int>q;
  for(int i=0;i<indegree.size();i++)
  {
    if(indegree[i]==0)
    {
      q.push(i);
      vis[i]=1;
    }
  }
  while(!q.empty())
  {
    int c=q.front();
    q.pop();
    ans.push_back(c);
    for(auto n:adj[c])
    {
      indegree[n]--;
      if(indegree[n]==0 and vis[n]==0)
      {
        q.push(n);
        vis[n]=1;
      }
    }
  }
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
    vector<vector<int>>ad(n+1);
    vector<int>indegree(n+1,0);
    for(int i=0;i<edges.size();i++)
    {
      int u=edges[i].first;
      int v=edges[i].second;
      ad[u].push_back(v);
      indegree[v]++;
    }

    vector<int>vis(n+1,0);
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)
      {
        bfs(i,vis,ad,indegree,ans);
      }
    }
    if(ans.size()==n)return 0;
    return 1;

}
