#include<bits/stdc++.h>
void dfs(vector<int>adj[],int i,int vis[],stack<int>&st)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
        {
            dfs(adj,it,vis,st);
        }
    }
    st.push(i);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int>ans;
    vector<int>adj[nodes];
    for(int i=0;i<graph.size();i++)
    {
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
    }
    int vis[nodes]={0};
    stack<int>st;
    for(int i=0;i<nodes;i++)
    {
        if (vis[i] == 0) {
            dfs(adj,i,vis,st);
        }
    }
    while(st.size()>0)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
